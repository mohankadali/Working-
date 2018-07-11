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
struct cdev *my_cdev;
char *devname="SPI";

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
static const struct spi_device_id spi_adc_id[] = {
    { "spi_adc", 0 },
    {}
};
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
	
  return 0;
}
static int spidev_probe(struct device *dev)
{
	printk("probe function call..\n");
	printk(" datails.. %s \n",dev->init_name);

  return 0;
}

static int spidev_remove(struct device *dev)
{
  printk("remove call function call..\n");
  printk(" datails.. %s \n",dev->init_name);

  return 0;
}
static struct spi_driver spidev_driver = {

	.driver = {
			 .owner = THIS_MODULE,
		   .name = "generic spi",
//		   .bus = &spi_bus_type,
		   .probe = spidev_probe,
		   .remove = spidev_remove,
	   },
	.id_table = spi_adc_id,
};

static int __init spi_dev_init(void)
{
	int res, status;
  printk (KERN_INFO "Initializing Character Device \n");

  status  = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);

  if (status < 0)
  {
    printk (KERN_NOTICE "Device numbers allocation failed: %d \n",status);
    goto err;
  }

  printk (KERN_INFO "Major number allocated = %d \n",MAJOR(mydev));
	printk(KERN_INFO "spi /dev entries driver\n");

	if (0 != (res = register_chrdev(MAJOR(mydev), "spi", &fops))) {
		goto out;
	}

/*	if (0 != (res = spi_add_driver(&spidev_driver))) {
	goto out_unreg;
	}
*/
	if (0 != (res = spi_register_driver(&spidev_driver))) {
  	goto out_unreg;
  }

#ifdef CONFIG_DEVFS_FS
	devfs_mk_dir("spi");
#endif
	return 0;
      err:
	unregister_chrdev(MAJOR(mydev), "spi");
			out_unreg:
	unregister_chrdev(MAJOR(mydev), "spi");
      out:
	printk(KERN_ERR "%s: Driver initialization failed\n", __FILE__);
	return res;
}
static void spi_dev_exit (void)
{
spi_unregister_driver(&spidev_driver);
devfs_remove("spi");
	unregister_chrdev_region(mydev, NR_DEVS);

		return;
}
module_init (spi_dev_init);
module_exit (spi_dev_exit);

