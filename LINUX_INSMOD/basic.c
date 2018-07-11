#include <linux/delay.h>
#include <linux/module.h>     /* Needed by all modules */
#include <linux/kernel.h>     /* Needed for KERN_INFO */
#include <linux/init.h>       /* Needed for the macros */
///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Akshat Sinha");

///< The description -- see modinfo
MODULE_DESCRIPTION("A simple Hello world LKM!");

///< The version of the module
MODULE_VERSION("0.1");

static int __init hello_start(void)
{
int x =5;
while(x){
    printk(KERN_EMERG "KERN_EMERG ...\n");
        printk(KERN_ALERT "KERN_ALERT  ...\n");
        printk(KERN_CRIT "KERN_CRIT ...\n");
        printk(KERN_ERR "KERN_ERR  ...\n");
        printk(KERN_WARNING "KERN_WARNING   ...\n");
        printk( KERN_NOTICE "KERN_NOTICE   ...\n");
        printk(KERN_INFO "KERN_INFO...\n");
        printk(KERN_DEBUG "KERN_DEBUG   ...\n");
        printk(KERN_DEFAULT "KERN_DEFAULT ...\n");
        msleep(1000);
        x--;
}
return 0;
}

static void __exit hello_end(void)
{
        printk(KERN_INFO "Goodbye Mr.\n");
}

module_init(hello_start);
module_exit(hello_end);
