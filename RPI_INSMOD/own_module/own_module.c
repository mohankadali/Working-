#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MOHAN, 2018");
MODULE_DESCRIPTION("Hello World Kernel Module for RPI");
static int hello_init(void)
{
    printk("Hello Kernel World....\n");
    return 0;
}
static void hello_exit(void)
{
    printk("Goodbye Kernel World\n");
}
module_init(hello_init);
module_exit(hello_exit);

