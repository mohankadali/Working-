
/** System Includes **/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/current.h>
#include <linux/mm.h>

MODULE_LICENSE("Dual BSD/GPL") ;

/** Constants **/

#define FIRST_MINOR 10
#define NR_DEVS 1 //Number of device numbers

//Function declarations for syscall definitions

extern int myOpen ( struct inode *inode, struct file *filep ) ;
extern int myRelease ( struct inode *in, struct file *fp ) ;
long myioctl ( struct file *fd, unsigned int pid, unsigned long cmd) ;

//Initialization routines

static int myInit ( void ) ;
static void myExit ( void ) ;

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = myOpen,
    .release = myRelease,
    .unlocked_ioctl = myioctl 
} ;

/* Global variables */

char *devname ; //contains device name
int majNo ;
static dev_t mydev ; //encodes major number & minor number device
struct cdev *my_cdev ; //holds character device driver descriptor

/* To accept input from the command line */

module_param(devname, charp, 0000) ;

//Class & device structures

static struct class *mychar_class ;
static struct device *mychar_device ;




long myioctl ( struct file *fd, unsigned int pid, unsigned long cmd )
{
    struct task_struct *p = current ;
    struct vm_area_struct *r ;
    char a[5] ;
  

    printk (KERN_INFO"Process ID -: %ld \n", cmd) ;
    r =  (p->mm)->mmap ;

    while ( r ) {
        if (r->vm_flags & VM_READ) {
            a[0] = 'r' ; 
        } else {
            a[0] = '_' ;
        }
        if (r->vm_flags & VM_WRITE) {
            a[1] = 'w' ;
        } else {
            a[1] ='_' ;
        }
        if (r->vm_flags & VM_EXEC) {
            a[2] = 'x' ;
        } else {
            a[2] = '_' ;
        }
        if (r->vm_flags & VM_SHARED) {
            a[3] = 's' ;
        } else {
            a[3] = 'p' ;
        }
        a[4] = '\0' ;
        
        if ( r->vm_file && (r->vm_pgoff != r->vm_start) ) {

            printk (KERN_INFO"%.8x - %.8x %s %.8x %.2d:%.2d %s", (unsigned int)r->vm_start, (unsigned int)r->vm_end, a, (unsigned int)(r->vm_pgoff << 12),(unsigned int) MAJOR(r->vm_file->f_path.dentry->d_sb->s_dev), (unsigned int) MINOR(r->vm_file->f_path.dentry->d_sb->s_dev),r->vm_file->f_path.dentry->d_iname ) ;
        }


        else {
            printk (KERN_INFO"%.8x - %.8x %s %.8d        ",(unsigned int) r->vm_start,(unsigned int) r->vm_end, a, 0 ) ;
        }



        if ( NULL == r->vm_next ) {
            printk (KERN_INFO"%.8x - %.8x %s %-8p       ", (unsigned int)r->vm_start, (unsigned int)r->vm_end, a, (void *)(r->vm_pgoff << 12) ) ;
        }


        r = r->vm_next ;
    }

    return 0 ;
}


/*
 * myInit: init function of the kernel module
 */

static int __init myInit ( void )
{
    int ret = -ENODEV ;
    int status ;

    //Allocating Device Numbers

    status = alloc_chrdev_region ( &mydev, FIRST_MINOR, NR_DEVS, devname ) ;

    if ( status < 0 ) {
        printk ( KERN_NOTICE "Device numbers allocation failed: %d\n", status ) ;
        goto err ;
    }

    printk ( KERN_INFO "Major number allocated= %d\n", MAJOR(mydev) ) ;
    my_cdev = cdev_alloc () ;//Alllocate memory for my_cdev

    if ( my_cdev == NULL ) {
        printk (KERN_ERR "cdev_alloc failed \n") ;
        goto err_cdev_alloc ;
    }

    cdev_init ( my_cdev, &fops ) ; //Initialize my_cdev with fops
    my_cdev->owner = THIS_MODULE ;
    status = cdev_add ( my_cdev, mydev, NR_DEVS ) ; //Add my_cdev to the list

    if ( status ) {
        printk ( KERN_ERR "cdev_add failed \n") ;
        goto err_cdev_add ;
    }

    //create a class and an entry in sysfs

    mychar_class = class_create (THIS_MODULE, devname) ;

    if ( IS_ERR (mychar_class )
       ) {
        printk ( KERN_ERR "class_creat () failed\n") ;
        goto err_class_create ;
    }

    //creates mychar_device in sysfs and a device entry
    //will be made in /dev directory

    mychar_device = device_create ( mychar_class, NULL, mydev, NULL, devname ) ;

    if ( IS_ERR ( mychar_device ) ) {
        printk (KERN_ERR "device_create () failed\n") ;
        goto err_device_create ;
    }

    return 0 ;
err_device_create:
    class_destroy ( mychar_class ) ;
err_class_create:
    cdev_del ( my_cdev ) ;
err_cdev_add:
    kfree ( my_cdev ) ;
err_cdev_alloc:
    unregister_chrdev_region ( mydev, NR_DEVS ) ;
err:
    return ret ;
}

/*
 * myExit: Cleanup function of the kernel module
 */

static void myExit ( void )
{
    printk ( KERN_INFO "Exiting the character Driver \n") ;
    device_destroy ( mychar_class, mydev ) ;
    class_destroy ( mychar_class ) ;
    cdev_del ( my_cdev ) ;
    unregister_chrdev_region ( mydev, NR_DEVS ) ;
    return ;
}

module_init ( myInit ) ;
module_exit ( myExit ) ;
