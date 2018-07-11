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

#define FIRST_MINOR_NUM 10
#define NR_OF_DEVS 1

static dev_t mydev;

MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");

struct cdev *my_cdev;
char *devname="spi_adc";

static int myOpen(struct inode *inode, struct file *filep);

//module_spi_driver(spidev_driver);
//ssize_t myread (struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
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
static struct spi_device *spi_prob_device;

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

static int spidev_probe(struct spi_device *dev)
{
	printk("probe function call..\n");
	printk("------------- %s\n",dev->dev.init_name);

	spi_prob_device = dev;

	printk("----cs %d == \n",dev->chip_select);
	printk("----bpw %d == \n",dev-> bits_per_word);
//	printk("----bpw %d == \n",dev-> bits_per_word);
	printk("----mode %d == \n",dev-> mode);
	printk("---irq %d == \n",dev-> irq);
	printk("----bpw %s == \n",dev->modalias);
	printk("----cs_gpio %d == \n",dev->cs_gpio);

	//dev->Chip_select = 0;
//	dev->bits_per_word = 24;
	dev->mode = SPI_MODE_0;
	 printk("----bpw %d == \n",dev-> bits_per_word);

	spi_setup(dev);

//	printk("0000000000000 %d \n",buff[0]);
/*

	 for(i=0; i < 10 ; i++ ) {
				printk(" %d \n",buff[i]);
	}

*/
/*
unsigned char start = 0x80;
unsigned char r1;
unsigned char cmd = 0x50;
unsigned char r2;
unsigned char dont = 0x00;
unsigned char r3;
*/
/*
*//*

if(	spi_write1(dev, buff1, 2) == 0) {
				printk("spi_write1 is sucses..\n");
} else {
				printk("spi_write1 is fail..\n");
}

*/

/*

if(spi_write(dev,&start,1) == 0) {
				printk("spi_write is SUCSESS..\n");
} else {
				printk("spi_write is fail..\n");
}
if(spi_read(dev,&r1,1) == 0) {
				printk("spi_read is SUCSESS..\n");
} else {
				printk("spi_write is fail..\n");
}
if(spi_write(dev,&cmd,1) == 0) {
				printk("spi_write is SUCSESS..\n");
} else {
				printk("spi_write is fail..\n");
}
if(spi_read(dev,&r2,1) == 0) {
				printk("spi_read is SUCSESS..\n");
} else {
				printk("spi_read is fail..\n");
}
if(spi_write(dev,&dont,1) == 0) {
				printk("spi_write is SUCSESS..\n");
} else {
				printk("spi_write is fail..\n");
}
if(spi_read(dev,&r3,1) == 0) {
				printk("spi_read is SUCSESS..\n");
} else {
				printk("spi_read is fail..\n");
}
*/
//printk("***************** %d *******%d*********%d****\n",r1, r2, r3);
/*
if(spi_read(dev,buff1,2) == 0) {
				printk("spi_read SUCSESS....\n");
} else {
				printk("spi_read fail....\n");

}
*/

unsigned int  buff = 0xD0000000;
if(	spi_read1(dev, &buff, sizeof(buff)) == 0) {
				printk("spi_read1 is sucses..\n");
} else {
				printk("spi_read1 is fail..\n");
}

  return 0;
}


//static int spi_read_reg(struct device *dev, unsigned char address, unsigned char *data);

static int spi_read1(struct spi_device *spi, void *buf, size_t len)
{
				printk("spi_read call ...\n");
/*struct spi_message	m;
				m.spi = spi;

				spi_message_init(&m);
				spi_message_add_tail(&t, &m);

				printk("DATA IS %x \n",*(int *)t.tx_buf);
				printk("llllllllllllllllll %d -----\n",spi_sync(spi, &m));

				printk(" DATAD  ===== %x \n",*(char*)t.rx_buf);
				return spi_sync(spi, &m);
*/


				printk("----cs %d == \n",spi->chip_select);
				printk("----bpw %d == \n",spi-> bits_per_word);
				printk("----bpw %d == \n",dev-> bits_per_word);
				printk("----mode %d == \n",spi-> mode);
				printk("---irq %d == \n",spi-> irq);
				printk("----bpw %s == \n",spi->modalias);
				printk("----cs_gpio %d == \n",spi->cs_gpio);

				struct spi_transfer t[2];
//				unsigned char cmd[3] = {0x01,0x0E,0x0F};
				unsigned char cmd[3] = {0x01,0xE0,0xFF};
				unsigned char res[3] = {0};

				struct spi_message  m;
				m.spi = spi;

				memset(t, 0, sizeof(t));

				spi_message_init(&m);

				t[0].tx_buf = cmd;
				t[0].rx_buf = res;
				t[0].len = 24;

				spi_message_add_tail(t, &m);

				spi_sync(spi, &m);

				printk("-----------------%c %c %c ---\n", res[0],res[1],res[2]);
return 0;

}

/*
static int spi_read_reg(struct device *dev, unsigned char address, unsigned char *data)
{
				struct spi_device *dev1 = spi_prob_device;
				address = 0x00;
				struct spi_device *spi = to_spi_device(dev1);

				*data = address | 0XD;

				if(spi_write_then_read(spi, data, 1, data, 1)) {
								printk("spi_write_then_read are fail...\n");
				} else {
									printk("spi_write_then_read are sucsecc...\n");
				}
				return 0;
}
*/
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
				.of_match_table = spi_adc_id,
	   },
		   .probe = spidev_probe,
		   .remove = spidev_remove,
//			 .id_table = spi_adc_id,
};

//module_spi_driver(spidev_driver);
/*
ssize_t myread (struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
				printk("read is SUCSECC..\n");
//				spi_read(&spidev_driver, buf, 2);
//				spi_read(spi, buf, 5);
}

*/
/*

int spi_read1(struct spi_client *client, int addr, char *buf, int len)
{
				struct spi_adapter *adap = client->adapter;
				struct spi_msg msg;
				int ret;

				msg.addr = addr;
				msg.flags = SPI_M_RD;
				msg.buf = buf;
				msg.len = len;

				ret = spi_transfer(adap, &msg, 1);
				return ret == 1 ? len : ret;
}

static ssize_t myRead(struct file *file, char *buf, int count,loff_t * offset)
{
				char *tmp;
				int ret;
#ifdef SPIDEV_DEBUG
				struct inode *inode = file->f_dentry->d_inode;
#endif
				struct spi_client *client = (struct spi_client *)file->private_data;
				unsigned long (*cpy_to_user) (void *to_user, const void *from,
												unsigned long len);
				void *(*alloc) (size_t, int);
				void (*free) (const void *);
				if (count > SPI_TRANSFER_MAX)
								count = SPI_TRANSFER_MAX;

				cpy_to_user = client->adapter->copy_to_user ? client->adapter->copy_to_user : copy_to_user;
				alloc = client->adapter->alloc ? client->adapter->alloc : kmalloc;
				free = client->adapter->free ? client->adapter->free : kfree;

				tmp = alloc(count, GFP_KERNEL);
				if (tmp == NULL)
								return -ENOMEM;

				DBG("spi-%d reading %d bytes.\n", MINOR(inode->i_rdev), count);

				ret = spi_read1(client, 0, tmp, count);
				if (ret >= 0)
								ret = cpy_to_user(buf, tmp, count) ? -EFAULT : ret;
				free(tmp);
				return ret;
}
*/
/*
static inline int spi_read(struct spi_device *spi, void *buf, size_t len)
{
				struct spi_transfer	t = {
								.rx_buf		= buf,
								.len		= len,
				};
				struct spi_message	m;

				spi_message_init(&m);
				spi_message_add_tail(&t, &m);
				return spi_sync(spi, &m);
}
*/

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
