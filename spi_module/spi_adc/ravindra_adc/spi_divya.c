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

#define FIRST_MINOR 10
#define NR_DEVS 1

static dev_t mydev;

MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");

struct cdev *my_cdev;
char *devname="spi_adc";

static int myOpen(struct inode *inode, struct file *filep);

static int myRelease (struct inode *in, struct file *fp);
static int spi_dev_init (void);
static void spi_dev_exit (void);

struct file_operations fops = {
    .owner      = THIS_MODULE,
    .open     = myOpen,
    .release    = myRelease,
//    .read     =   myread,
};

/*
struct spi_driver {
  const struct spi_device_id * id_table;
  int (* probe) (struct spi_device *spi);
  int (* remove) (struct spi_device *spi);
  void (* shutdown) (struct spi_device *spi);
  struct device_driver driver;
}; 
*//*
struct device_driver {
  const char * name;
  struct bus_type * bus;
  struct module * owner;
  const char * mod_name;
  bool suppress_bind_attrs;
  const struct of_device_id * of_match_table;
  int (* probe) (struct device *dev);
  int (* remove) (struct device *dev);
  void (* shutdown) (struct device *dev);
  int (* suspend) (struct device *dev, pm_message_t state);
  int (* resume) (struct device *dev);
  const struct attribute_group ** groups;
  const struct dev_pm_ops * pm;
  struct driver_private * p;
};*/ 
/*
---------------- i2c_driver----------------------------

struct i2c_driver {
  unsigned int class;
  int (* attach_adapter) (struct i2c_adapter *);
  int (* probe) (struct i2c_client *, const struct i2c_device_id *);
  int (* remove) (struct i2c_client *);
  void (* shutdown) (struct i2c_client *);
  void (* alert) (struct i2c_client *, unsigned int data);
  int (* command) (struct i2c_client *client, unsigned int cmd, void *arg);
  struct device_driver driver;
  const struct i2c_device_id * id_table;
  int (* detect) (struct i2c_client *, struct i2c_board_info *);
  const unsigned short * address_list;
  struct list_head clients;
}; 
*/

static struct class *mychar_class;
static struct device *mychar_device;

int myOpen(struct inode *inode, struct file *filep)
{
	printk("muOpen is invoked\n");
	return 0;
	
}

int myRelease (struct inode *in, struct file *fp)
{
  printk (KERN_INFO "File released \n");
  return 0;
}

size_t myread (struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	printfk("read function is calling..\n");	
  return 0;
}

static int spidev_probe(struct spi_device *dev)
{
	printk("probe function call..\n");

  return 0;
}

static int spidev_remove(struct spi_device *dev)
{
  printk("remove call function call..\n");

  return 0;
}

static const struct spi_device_id spi_adc_id[] = {
    { "spi_adc", 0 },
    {}
};

MODULE_DEVICE_TABLE (spi, spi_adc_id);

static struct spi_driver spidev_driver = {

	.driver = {
				 .owner = THIS_MODULE,
			   .name = "spi_adc",
//		   .bus = &spi_bus_type,
	   },
		   .probe = spidev_probe,
		   .remove = spidev_remove,
			 .id_table = spi_adc_id
};

static int __init spi_dev_init(void)
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
  my_cdev = cdev_alloc(); //Allocate memory for my_cdev
  if(my_cdev == NULL) {
    printk(KERN_ERR "cdev_alloc failed \n");
    goto err_cdev_alloc;
  } else {
    printk(KERN_ERR "cdev_alloc SUCSESS \n");
  }

  cdev_init(my_cdev, &fops);  //Initialize my_cdev with fops
  my_cdev->owner = THIS_MODULE;

  status = cdev_add(my_cdev, mydev, NR_DEVS); //Add my_cdev to the list
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

  if (0 != (ret = spi_register_driver(&spidev_driver))) {
    goto err_device_create;
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
static void spi_dev_exit (void)
{
	spi_unregister_driver(&spidev_driver);
  printk(KERN_INFO "Exiting the Character Driver \n");

  device_destroy(mychar_class, mydev);
  class_destroy(mychar_class);
  cdev_del(my_cdev);
  unregister_chrdev_region(mydev, NR_DEVS);

  return;
}

module_init (spi_dev_init);
module_exit (spi_dev_exit);

