#include <linux/module.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/list.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/compat.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/cdev.h>
#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/ioctl.h>
#include <linux/mm.h>
#include <linux/gpio.h>


#define FIRST_MINOR_NUM 11
#define NR_OF_DEVS 1
#define LEN 4096

// Gpl License Mecro
MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");

static dev_t mydev;
struct cdev *my_cdev;

// our Driver Name
char *devname="spi_adc";

// open function call
static int spidev_open(struct inode *inode, struct file *filep);

// read data from ADC
ssize_t spidev_read(struct file *, char __user *, size_t, loff_t *);

// release memory
static int spidev_Release (struct inode *in, struct file *fp);

// invoke when, doing insmod
static int spi_dev_init (void);

// exit invoke when doing rmmod
static void spi_dev_exit (void);

// ioctl
static long my_ioctl(struct file *f, unsigned int cmd, unsigned long arg);
//static int my_ioctl(struct inode *i, struct file *f, unsigned int cmd, unsigned long arg);

int my_map(struct file *filp, struct vm_area_struct *vma);

// file operation structure initializetion
struct file_operations fops = {

				.owner      		= THIS_MODULE,
		    .open     			= spidev_open,
    		.release    		= spidev_Release,
		    .read     			= spidev_read,
		    .unlocked_ioctl = my_ioctl,
				.mmap						= my_map,
};

static struct class *mychar_class;
static struct device *mychar_device;

static struct gpio buttons[] = {
				{ 17, GPIOF_IN, "BUTTON 1" },
};

static int button_irqs[] = { -1, -1 };


static irqreturn_t button_isr(int irq, void *data)
{
				printk("++++++++++++++++++\n");
				printk(KERN_NOTICE "Interrupt...gpio value: %d\n", gpio_get_value(buttons[0].gpio));

				return IRQ_HANDLED;
}

int my_map(struct file *filp, struct vm_area_struct *vma)
{
				return 0;
}

static long my_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
//static int my_ioctl(struct inode *i, struct file *f, unsigned int cmd, unsigned long arg)
{
				if(cmd == 1) {

				} else {
								printk("IOCTL is not invoked...\n");
				}
				return 0;
}

int spidev_open(struct inode *inode, struct file *filep)
{
	printk("muOpen is invoked\n");
	return 0;

}

int spidev_Release (struct inode *in, struct file *fp)
{
  printk (KERN_INFO "File released \n");
  return 0;
}

static int spidev_probe(struct spi_device *dev)
{
  return 0;
}
ssize_t spidev_read(struct file * fp, char __user * ch, size_t sz, loff_t * lf)
{

				return 0;
}

static int spidev_remove(struct spi_device *dev)
{
  printk("remove call function call..\n");
  return 0;
}

// Register Device name
static const struct of_device_id spi_adc_id[] = {
    { .compatible = "spi_adc",  },
		{}
};

// Update device table
MODULE_DEVICE_TABLE(of, spi_adc_id);

static struct spi_driver spidev_driver = {

	.driver = {

				 	.owner = THIS_MODULE,
			  	.name = "spi_adc",
					.of_match_table = of_match_ptr(spi_adc_id),

	   	},

				.probe = spidev_probe,
		   	.remove = spidev_remove,
};

// invoke when driver is insert into kernal.
static int __init spi_dev_init(void)
{

				int ret = -ENODEV;
				int status;
				int r =0;
				struct task_struct *get_pid1;
				get_pid1 = current;
				printk( "current pid :%d\n",get_pid1 ->pid);

				// Allocation Device Numbers
				status = alloc_chrdev_region( &mydev, FIRST_MINOR_NUM, NR_OF_DEVS, devname);
				if(status < 0) {
								printk(KERN_NOTICE "Device number allocation failed: %d \n", status);
								goto err;
				} else {
								printk(KERN_NOTICE "Device number allocation SUCSESS");
				}

				printk(KERN_INFO "Major number allocated = %d \n", MAJOR(mydev));
				printk(KERN_INFO "Minor number allocated = %d \n", MINOR(mydev));

				// Allocate Memory for my_cdev
				my_cdev = cdev_alloc();
				if(my_cdev == NULL) {
								printk(KERN_ERR "cdev_alloc failed \n");
								goto err_cdev_alloc;
				} else {
								printk(KERN_ERR "cdev_alloc SUCSESS \n");
				}

				// Initialize my_cdev with fops
				cdev_init(my_cdev, &fops);
				my_cdev->owner = THIS_MODULE;

				// Add my_cdev to the list
				status = cdev_add(my_cdev, mydev, NR_OF_DEVS);
				if(status) {
								printk(KERN_ERR "cdev_add failed \n");
								goto err_cdev_add;
				} else {
								printk(KERN_ERR "cdev_add SUCSESS");
				}

				//Creating a class and an entry in sysfs
				mychar_class = class_create(THIS_MODULE, devname);
				if(IS_ERR(mychar_class)) {
								printk(KERN_ERR "class_create() failed....... \n");
								goto err_class_create;
				} else {
								printk(KERN_ERR "class_create() SUCSESS........\n");
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

				// Register driver
				if (0 != (ret = spi_register_driver(&spidev_driver))) {
								goto err_device_create;
				} else {
								printk(KERN_ERR "spi_register_driver() SUCSESS");
				}

        r  = gpio_request_array(buttons, ARRAY_SIZE(buttons));

				if(r) {
								printk("gpio_request_array ... fail..\n");
				} else {
								printk("gpio_request_array ... SUCSESS\n");
				}

				r = gpio_to_irq(buttons[0].gpio);

				if(r < 0) {
								printk("gpio_to_irq ... fail..\n");
								goto gpio_free_error;
				} else {
								printk("gpio_request_array ... SUCSESS\n");
				}

				button_irqs[0] = r;

				ret = request_irq(button_irqs[0],
													button_isr,
													IRQF_TRIGGER_RISING /*| IRQF_DISABLED*/,
													"pikeybrd#button1", NULL);

				if(ret) {
								printk(KERN_ERR "Unable to request IRQ: %d\n", ret);
								goto gpio_irq;
				} else {
								printk(KERN_ERR "request IRQ  SUCSESS: %d\n", ret);
				}

				return 0;

gpio_free_error:
				gpio_free_array(buttons, ARRAY_SIZE(buttons));

gpio_irq:
				free_irq(button_irqs[0], NULL);

err_device_create:
				class_destroy(mychar_class);

err_class_create:
				cdev_del(my_cdev);

err_cdev_add:
				kfree(my_cdev);

err_cdev_alloc:
				unregister_chrdev_region(mydev, NR_OF_DEVS);

err:
				return ret;

}

// invoke when we remove driver into kernal
static void spi_dev_exit (void)
{
				// unregistere driver
				gpio_free_array(buttons, ARRAY_SIZE(buttons));
				free_irq(button_irqs[0], NULL);
				spi_unregister_driver(&spidev_driver);

				printk(KERN_INFO "Exiting the Character Driver \n");

				device_destroy(mychar_class, mydev);
				class_destroy(mychar_class);
				cdev_del(my_cdev);
				unregister_chrdev_region(mydev, NR_OF_DEVS);

				return;
}

module_init (spi_dev_init);
module_exit (spi_dev_exit);
