#ifdef CONFIG_SPI_DEBUG
#define DEBUG
#endif				/* CONFIG_SPI_DEBUG */

#include <linux/init.h>
#include <linux/spi/spi.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/platform_device.h>
#include <linux/bcd.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

#define FIRST_MINOR     10                                                      
#define NR_DEVS         1   /* Number of device numbers */ 
#define SPI_TRANSFER_MAX	65535
#define SPI_ADAP_MAX		32

/* struct file_operations changed too often in the 2.1 series for nice code */

//static ssize_t spidev_read(struct file *file, char *buf, size_t count,
//								loff_t * offset);
//static ssize_t spidev_write(struct file *file, const char *buf, size_t count,
//								loff_t * offset);

static int spidev_open(struct inode *inode, struct file *file);
static int spidev_release(struct inode *inode, struct file *file);
//static int spidev_ioctl(struct inode *inode, struct file *file,
//								unsigned int cmd, unsigned long arg);
static int __init spi_dev_init(void);
static void spidev_cleanup(void);
//static int spidev_probe(struct device *dev);
static int spidev_remove(struct device *dev);
char *devname = "i2c_rtc";                                                      
int majNo;                                                                      
static dev_t mydev;                                                             
struct cdev *my_cdev;                                                           
static struct class *mychar_class;                                              
static struct device *mychar_device;
static struct file_operations fops = {
	//				.owner = THIS_MODULE,
	//				.llseek = no_llseek,
	//				.read = spidev_read,
	//				.write = spidev_write,
	.open = spidev_open,
	.release = spidev_release,
};
static struct spi_driver spidev_driver = {
	//.owner = THIS_MODULE,
	.driver = {
		.name 	= "generic spi",
		.bus 		= &spi_bus_type,
		//.probe 	= spidev_probe,
		.remove = spidev_remove,
	},
	//.supported_ids = SPI_IDS,
	//.minor = 0,
};
static int spidev_remove(struct device *dev)
{
	return 0;
}
int spidev_open(struct inode *inode, struct file *file)
{
	printk (KERN_INFO "Open successful\n"); 
	return 0;
}
static int spidev_release(struct inode *inode, struct file *file)
{
	return 0;
}
static int __init spi_dev_init(void)
{
	int ret = -ENODEV;
	int status;
	struct task_struct *get_pid1;
	printk(KERN_INFO "spi /dev entries driver\n");
	get_pid1 = current;
	printk( "current pid :%d\n", get_pid1 ->pid);
	// Allocation Device Numbers
	status = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_NOTICE "Device number allocation failed: %d \n", status);
		goto err;
	} else {
		printk(KERN_NOTICE "Device number allocation SUCSESS");
	}
	majNo = MAJOR(mydev);
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
		printk(KERN_ERR "class_create() failed ----\n");
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
	if (0 != (ret = spi_register_driver (&spidev_driver))) {
		goto err_device_create;
	}
#ifdef CONFIG_DEVFS_FS
	devfs_mk_dir("spi");
#endif
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
static void spidev_cleanup(void)
{
	spi_unregister_driver(&spidev_driver);
#ifdef CONFIG_DEVFS_FS
	devfs_remove("spi");
#endif
	unregister_chrdev(majNo, "spi");
}
MODULE_DESCRIPTION("SPI /dev entries driver");
MODULE_LICENSE("GPL");
module_init(spi_dev_init);
module_exit(spidev_cleanup);
