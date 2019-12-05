/** System Includes **/
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

/** Constants **/
#define FIRST_MINOR 10
#define NR_DEVS 2	//Number of device numbers

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myioctl(struct file *fp, unsigned int pid, unsigned long);

//Initialization routines
static int myInit(void);
static void myExit(void);

int a = 0;

/* GLobal variables */
char *devname="myChar";	//contains device name
int majNo;
static dev_t mydev;	//encodses major number and minor number
struct cdev *my_cdev;	//holds character device driver discriptor


//class and device structure
static struct class *mychar_class;
static struct device *mychar_device;
//ioctl
long myioctl(struct file *fp, unsigned int pid, unsigned long num )
{
	struct module *ptr = THIS_MODULE;
	struct task_struct *my_task = current;

	printk(KERN_INFO "my_pid in module %d\n", my_task->pid);
	printk(KERN_INFO "comm string is %s\n", my_task->comm);
	printk(KERN_INFO "module name %s\n", ptr->name);

	return 0;
}
/*
 * myOpen: open function of the pseudo driver
 */

int myOpen(struct inode *inode, struct file *filep)
{
	printk ("Hello\n");
	printk(KERN_INFO "Open successful\n");
	return 0;
}

/*
 * myRelease: close function of the pseudo driver
 */

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File releaseed \n");
	return 0;
}

struct file_operations fops = {

	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myioctl

};
/*
 * myInit: init function of the kernel module\
 */

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	struct task_struct *get_pid1;
	   get_pid1 = current;
    printk( "current pid :%d\n",get_pid1 ->pid);

	// Allocation Device Numbers
	status = alloc_chrdev_region( &mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_NOTICE "Device number allocation failed: %d \n", status);
		goto err;
	} else {
		printk(KERN_NOTICE "Device number allocation SUCSESS");
	}

	printk(KERN_INFO "Major number allocated = %d \n", MAJOR(mydev));
	printk(KERN_INFO "Minor number allocated = %d \n", MINOR(mydev));
	my_cdev = cdev_alloc();	//Allocate memory for my_cdev
	if(my_cdev == NULL) {
		printk(KERN_ERR "cdev_alloc failed \n");
		goto err_cdev_alloc;
	} else {
		printk(KERN_ERR "cdev_alloc SUCSESS \n");
	}

	cdev_init(my_cdev, &fops);	//Initialize my_cdev with fops
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);	//Add my_cdev to the list
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	} else {
		printk(KERN_ERR "cdev_add SUCSESS");
	}

	//Create a class and an entry in sysfs

	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_class)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	} else {
		printk(KERN_ERR "class_create() SUCSESS");
	}

	//create mychar_device in sysfs and an
	//device entry will be made in /dev directory

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed \n");
		goto err_device_create;
	} else {
		printk(KERN_ERR "device_create() SUCSESS");
	}

	return 0;

err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;
}

/*
 * myExit: cleanup function of the kernel module
 */

static void myExit(void)
{
	printk(KERN_INFO "Exiting the Character Driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

module_init(myInit);
module_exit(myExit);
