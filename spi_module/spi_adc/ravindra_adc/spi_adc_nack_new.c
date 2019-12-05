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

static dev_t mydev;

MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");

struct cdev *my_cdev;
char *devname="spi_adc";

static int myOpen(struct inode *inode, struct file *filep);
ssize_t spidev_read (struct file *, char __user *, size_t, loff_t *);
//module_spi_driver(spidev_driver);
//ssize_t myread (struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
static int myRelease (struct inode *in, struct file *fp);
static int spi_dev_init (void);
static void spi_dev_exit (void);

//ssize_t (*read) (struct file *, char *, size_t, loff_t *);



struct file_operations fops = {
    .owner      = THIS_MODULE,
    .open     = myOpen,
    .release    = myRelease,
//    .read     =   spidev_read,
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
static struct spi_device *spi_prob_dev;

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

static int spi_read1(struct spi_device *spi, void *buf, size_t len);
static int spi_write1(struct spi_device *spi, void *buf, size_t len);
static void  ll(void);


static int spidev_probe(struct spi_device *dev)
{
	printk("probe function call.000000000000000000.\n");
	printk("------------- %s\n",dev->dev.init_name);

	spi_prob_dev = dev;
/*
	printk("----cs %d == \n",dev->chip_select);
	printk("----bpw %d == \n",dev-> bits_per_word);
//	printk("----bpw %d == \n",dev-> bits_per_word);
	printk("----mode %d == \n",dev-> mode);
	printk("---irq %d == \n",dev-> irq);
	printk("----bpw %s == \n",dev->modalias);
	printk("----cs_gpio %d == \n",dev->cs_gpio);
	printk(")))))))))))))))))))))))))))))))))))))\n");
	//dev->Chip_select = 0;
//	dev->bits_per_word = 8;
//	dev->mode = SPI_MODE_0;

	 printk("----bpw %d == \n",dev-> bits_per_word);
printk("%d %d\n",dev->master->bus_num,dev->chip_select);
	dev->mode = SPI_MODE_0;
*/
	spi_setup(dev);
	ll();
  return 0;
}


//static int spi_read_reg(struct device *dev, unsigned char address, unsigned char *data);
//static int read(struct spi_device *spi, void *buf, size_t len)
//ssize_t spidev_read (struct file * fp, char __user * ch, size_t sz, loff_t * lf)
static void ll()
{

/*
	 			struct spi_message	m;
				m.spi = spi;

				spi_message_init(&m);
				spi_message_add_tail(&t, &m);

				printk("DATA IS %x \n",*(int *)t.tx_buf);
				printk("llllllllllllllllll %d -----\n",spi_sync(spi, &m));

				printk(" DATAD  ===== %x \n",*(char*)t.rx_buf);
				return spi_sync(spi, &m);
*//*
				printk("%d %d\n",spi_prob_dev->master->bus_num,spi_prob_dev->chip_select);

				printk("----cs %d == \n" ,spi_prob_dev->chip_select);
				printk("----bpw %d == \n",spi_prob_dev-> bits_per_word);
				printk("----mode %d == \n",spi_prob_dev-> mode);
				printk("---irq %d == \n" ,spi_prob_dev-> irq);
				printk("----bpw %s == \n",spi_prob_dev->modalias);
				printk("----cs_gpio %d == \n",spi_prob_dev->cs_gpio);
*/
				/*
				struct spi_transfer t[2];
				u8 cmd[3] = {0x01,0xE0,0xFF};
				int count = 24;
				char *buf, res[3] ;
				struct spi_message m;

				buf = res;
				memset(t, 0, sizeof t);
				printk("spi_read call .-------------..\n");
				t[0].tx_buf = cmd;
//				t[0].rx_buf = buf;
				t[0].len = 24;

				spi_message_init(&m);

				spi_message_add_tail(&t[0], &m);

				if(spi_prob_dev == NULL ) {
								printk("SPi is NULL ...\n");
				} else {
				printk("-++++++++++++%x++%x+++%x++++++++++++++++++\n", t[0].tx_buf,cmd[1],cmd[2]);
				printk("------> %d <----- \n",spi_sync(spi_prob_dev, &m));
//								printk("----- %c \t %c \t %c \t \n",res[0],res[1],res[2]);
				}
				*/
				//unsigned char cmd [3] = {0x80,0xA0,0xFF};
//				unsigned char cmd [2] = {0xD0,0xFF};
				unsigned char cmd [3] = {0x01,0xA0,0x00};
				unsigned char buf [3] = {0x00,0x00,0x00};
				int i = 0;
				char *p = &i;
				struct spi_transfer t =  {
								.tx_buf     = cmd,
								.rx_buf     = buf,
								.len        = 3,
								.bits_per_word = 8,
				};

				struct spi_message  m;

				spi_message_init(&m);
				spi_message_add_tail(&t, &m);
				if( spi_sync(spi_prob_dev, &m) == 0) {

								printk("sync is SUCSESS----->>>>>>\n");
								printk("----- %x -----\t %x -----\t %x---- \t \n",buf[0],buf[1],buf[2]);

								*p = buf[2];
								++p;
								*p = buf[1];
								i = i & 0x000FFF;
								printk("---------------> %d <-------------\n", i);

int k,l,m;
								for(k = 7 ; k >=0 ; k--)
												printk(" 2-> %d  ",(buf[2] >> k ) & 1);
printk("---------------------------------------------\n");
								for(l = 7 ; l >=0 ; l--)
												printk(" 1-> %d  ",(buf[1] >> l ) & 1);
printk("____________________________________\n");
								i = (4096 * i) / 5;

								printk(" input analog voltage is %d \n ", ((i*5)/4095));
int j = 0;
								for(j =( (sizeof(int) * 8) - 1); j >= 0 ; j--)
												printk("%d   ",(i>>j) & 1);
								printk("---------------> %d <-------------\n", i);

				} else {
								printk("sync is FAIL.......\n");
				}

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
