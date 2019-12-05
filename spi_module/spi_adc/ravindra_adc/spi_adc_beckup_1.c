#include <linux/init.h>
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

#define FIRST_MINOR_NUM 11
#define NR_OF_DEVS 1

// Gpl License
MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");

//
static dev_t mydev;
struct cdev *my_cdev;
char *devname="spi_adc";

// open function call
static int spidev_open(struct inode *inode, struct file *filep);

// read data from ADC
ssize_t spidev_read(struct file *, char __user *, size_t, loff_t *);

// release memory
static int spidev_Release (struct inode *in, struct file *fp);

// initializetion driver
static int spi_dev_init (void);

// exit
static void spi_dev_exit (void);


// file operation structure
struct file_operations fops = {
    .owner      = THIS_MODULE,
    .open     	= spidev_open,
    .release    = spidev_Release,
    .read     	= spidev_read,
};

/*
struct spi_driver {
  const struct spi_device_id * id_table;
  int (* probe) (struct spi_device *spi);
  int (* remove) (struct spi_device *spi);
  void (* shutdown) (struct spi_device *spi);
  struct device_driver driver;
};
*/

/*
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

static struct class *mychar_class;
static struct device *mychar_device;
static struct spi_device *spi_prob_dev;

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

static int spi_read1(struct spi_device *spi, void *buf, size_t len);
static int spi_write1(struct spi_device *spi, void *buf, size_t len);

static int spidev_probe(struct spi_device *dev)
{
	printk("probe function call..\n");
	printk("%s\n",dev->dev.init_name);

	spi_prob_dev = dev;

	printk("----> CHIP SELECT %d == \n"		,dev->chip_select);
	printk("----> BIT PER WORD %d == \n"	,dev-> bits_per_word);
	printk("----> SPI MODE %d == \n"			,dev-> mode);
	printk("----> IRQ %d == \n"						,dev-> irq);
	printk("----> SPI NAME %s == \n"			,dev->modalias);
	printk("----> CS GPIO NUMBER %d == \n",dev->cs_gpio);

	spi_setup(dev);
  return 0;
}

ssize_t spidev_read(struct file * fp, char __user * ch, size_t sz, loff_t * lf)
{

				printk("spi_adc_called..\n");

				unsigned char cmd [3] = {0x01,0xA0,0x00};
				unsigned char buf [3] = {0x00,0x00,0x00};

				int i = 0;
				char *p = &i;

				struct spi_transfer t 	= {

								.tx_buf     		= cmd,
								.rx_buf     		= buf,
								.len        		= 3,
								.bits_per_word 	= 8,

				};

				struct spi_message  m;

				spi_message_init(&m);
				spi_message_add_tail(&t, &m);

				if( spi_sync(spi_prob_dev, &m) == 0) {

								printk("sync is SUCSESS\n");

								*p = buf[2];
								++p;
								*p = buf[1];
								i = i & 0x000FFF;

								printk("final output num data -> %d \n", i);

    		        int res = copy_to_user(ch, &i, sizeof(int));

								if(res == 0){
												printk("COPY_TO_USER ARE SUCSECCCC..\n");
								} else {
												printk("COPY_TO_USER ARE FAILLL..\n");
								}
								/*printk("====================================================\n");

int k,l;
char *n;
int m;
								for(k = 7 ; k >=0 ; k--)
												printk(" 2-> %d  ",(buf[2] >> k ) & 1);
printk("---------------------------------------------\n");
								for(l = 7 ; l >=0 ; l--)
												printk(" 1-> %d  ",(buf[1] >> l ) & 1);
printk("____________________________________________\n");n = &i;
								i =  (4096 * i) / 5;
								printk("00000000000000000000000000 input analog voltage is %f \n ",m =((m*5) / 4096));

int j = 0,count = 1;
								for(j =( (sizeof(int) * 8) - 1); j >= 0 ; j--)
												printk("%d , %d ",(i>>j) & 1, j);
								printk("---------------> %d <-------------\n", i);

				} else {
								printk("sync is FAIL.......\n");
				}
				*/
				} else {
								printk("sync is FAIL.......\n");
				}


				return 0;
}

static int spidev_remove(struct spi_device *dev)
{
  printk("remove call function call..\n");
  return 0;
}

/*
static const struct spi_device_id spi_adc_id[] = {
    { "spi_adc",  },
    {}
};
*/

static const struct of_device_id spi_adc_id[] = {
    { .compatible = "spi_adc",  },
    {}
};

MODULE_DEVICE_TABLE(of, spi_adc_id);

static struct spi_driver spidev_driver = {

	.driver = {

				 .owner = THIS_MODULE,
			   .name = "spi_adc",
//		   .bus = &spi_bus_type,
				.of_match_table = of_match_ptr(spi_adc_id),

	   },
		   .probe = spidev_probe,
		   .remove = spidev_remove,
//			 .id_table = spi_adc_id,
};

static int __init spi_dev_init(void)
{
int ret = -ENODEV;
int status;

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
  my_cdev = cdev_alloc(); //Allocate memory for my_cdev
  if(my_cdev == NULL) {
    printk(KERN_ERR "cdev_alloc failed \n");
    goto err_cdev_alloc;
  } else {
    printk(KERN_ERR "cdev_alloc SUCSESS \n");
  }

  cdev_init(my_cdev, &fops);  //Initialize my_cdev with fops
  my_cdev->owner = THIS_MODULE;

  status = cdev_add(my_cdev, mydev, NR_OF_DEVS); //Add my_cdev to the list
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

  if (0 != (ret = spi_register_driver(&spidev_driver))) {
    goto err_device_create;
  } else {
		printk(KERN_ERR "spi_register_driver() SUCSESS");
	}

  return 0;

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

//EXPORT_SYMBOL_GPL(spi_register_driver);
static void spi_dev_exit (void)
{
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
