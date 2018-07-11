
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files li        ked fops. 
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/version.h>

MODULE_LICENSE("Dual BSD/GPL") ;


int myOpen ( struct inode *inode, struct file *filep )
{
    printk (KERN_INFO "open successful\n") ;
    return 0 ;
}


EXPORT_SYMBOL_GPL(myOpen);


