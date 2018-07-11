
/*include the system files  */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/export.h>

MODULE_LICENSE("Dual BSD/GPL");

/*my_open function for psudo driver */

int my_Open (struct inode * inode , struct file * filep )
{
	printk (KERN_INFO  "open successful \n");
	return 0;
}
EXPORT_SYMBOL_GPL (my_Open);
