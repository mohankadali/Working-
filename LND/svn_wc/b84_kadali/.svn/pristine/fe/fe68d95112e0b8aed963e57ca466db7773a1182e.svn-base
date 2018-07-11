#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files li        ked fops. 
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/version.h>


MODULE_LICENSE("Dual BSD/GPL") ;

int myRelease ( struct inode *in, struct file *fp )
{
    printk (KERN_INFO "File released\n") ;
    return 0 ;
}
EXPORT_SYMBOL_GPL(myRelease);

