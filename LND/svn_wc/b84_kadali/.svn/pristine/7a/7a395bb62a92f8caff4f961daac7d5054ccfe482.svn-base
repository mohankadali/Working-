
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


/*my_release function to release the psudo  driver  */
int my_Release (struct inode * in , struct file * fp )
{
        printk (KERN_INFO  "file released \n");
        return 0;
}

	 EXPORT_SYMBOL_GPL(my_Release);	
