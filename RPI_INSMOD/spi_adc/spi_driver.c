#ifdef CONFIG_SPI_DEBUG
#define DEBUG
#endif				/* CONFIG_SPI_DEBUG */

#include <linux/init.h>
//#include <linux/config.h>
#include <linux/spi/spi.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/platform_device.h>
//#include <linux/smp_lock.h>

//#include <linux/devfs_fs_kernel.h>
#include <linux/bcd.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

#include "spi.h"

#define FIRST_MINOR     10                                                      
#define NR_DEVS         1   /* Number of device numbers */ 
#define SPI_TRANSFER_MAX	65535
#define SPI_ADAP_MAX		32

/* struct file_operations changed too often in the 2.1 series for nice code */

//static ssize_t spidev_read(struct file *file, char *buf, size_t count,
//								loff_t * offset);
//static ssize_t spidev_write(struct file *file, const char *buf, size_t count,
//								loff_t * offset);

static int spidev_open(struct inode *inode, struct file *file);
static int spidev_release(struct inode *inode, struct file *file);
//static int spidev_ioctl(struct inode *inode, struct file *file,
//								unsigned int cmd, unsigned long arg);
static int __init spi_dev_init(void);

static void spidev_cleanup(void);

//static int spidev_probe(struct device *dev);
static int spidev_remove(struct device *dev);

char *devname = "i2c_rtc";                                                      
int majNo;                                                                      
static dev_t mydev;                                                             
struct cdev *my_cdev;                                                           
                                                                                
static struct class *mychar_class;                                              
static struct device *mychar_device;

static struct file_operations fops = {
				.owner = THIS_MODULE,
//				.llseek = no_llseek,
//				.read = spidev_read,
//				.write = spidev_write,
				.open = spidev_open,
				.release = spidev_release,
};

//SPI_IDS_TABLE_BEGIN
//SPI_ID_ANY 
//SPI_IDS_TABLE_END 

static struct spi_driver spidev_driver = {
//				.owner = THIS_MODULE,
				.driver = {
								.name 	= "generic spi",
								.bus 		= &spi_bus_type,
//								.probe 	= spidev_probe,
								.remove = spidev_remove,
				},
//				.supported_ids = SPI_IDS,
//				.minor = 0,
};
/*
static int spidev_probe(struct device *dev)
{
				spidev_driver_data_t *drvdata;
				int err = 0;

				if (NULL == dev) {
								printk(KERN_ERR "%s: probing the NULL device!\n", __FUNCTION__);
								err = -EFAULT;
								goto probe_out;
				}

				drvdata = (spidev_driver_data_t *) kmalloc(sizeof(spidev_driver_data_t),
												GFP_KERNEL);
				if (NULL == drvdata) {
								pr_debug("%s: allocating drvdata failed\n", __FUNCTION__);
								err = -ENOMEM;
								goto probe_out;
				}

				drvdata->minor = spidev_driver.minor  ;
				pr_debug("%s: setting device's(%p) minor to %d\n",
												__FUNCTION__, dev, drvdata->minor);
				dev_set_drvdata(dev, drvdata);
#ifdef CONFIG_DEVFS_FS
				devfs_mk_cdev(MKDEV(majNo, drvdata->minor),
												S_IFCHR | S_IRUSR | S_IWUSR, "spi/%d", drvdata->minor);
#endif
				printk ("%s: Registered as minor %d\n", __FUNCTION__, drvdata->minor);
probe_out:	
				return err;
}
*/
static int spidev_remove(struct device *dev)
{
				spidev_driver_data_t *drvdata;
				int err = 0;

				if (NULL == dev) {
								printk(KERN_ERR "%s: removing the NULL device\n", __FUNCTION__);
				}

				drvdata = (spidev_driver_data_t *) dev_get_drvdata(dev);
				if (NULL == drvdata) {
								pr_debug("%s: oops, drvdata is NULL !\n", __FUNCTION__);
								err = -ENODEV;
								goto remove_out;
				}
#ifdef CONFIG_DEVFS_FS
				devfs_remove("spi/%d", drvdata->minor);
#endif
				kfree(drvdata);
				pr_debug("%s: device removed\n", __FUNCTION__);
remove_out:	
				return err;
}

#if 0

static ssize_t spidev_read(struct file *file, char *buf, size_t count,
								loff_t * offset)
{
				char *tmp;
				int ret = 0;
//#ifdef DEBUG
				struct inode *inode = file->f_dentry->d_inode;
//#endif
				struct spi_adapter *adap = (struct spi_adapter *)file->private_data;
				unsigned long (*cpy_to_user) (void *to_user, const void *from,
												unsigned long len);
				void *(*alloc) (size_t, int);
				void (*free) (const void *);
				if (count > SPI_TRANSFER_MAX)
								count = SPI_TRANSFER_MAX;

				cpy_to_user = adap->copy_to_user ? adap->copy_to_user : copy_to_user;
				alloc = adap->alloc ? adap->alloc : kmalloc;
				free = adap->free ? adap->free : kfree;

				/* copy user space data to kernel space. */
				tmp = alloc(count, GFP_KERNEL);
				if (tmp == NULL) {
								ret = -ENOMEM;
								goto read_out;
				}

				printk ("spi-%d reading %zu bytes.\n", MINOR(inode->i_rdev), count);

				ret = spi_read(adap, 0, tmp, count);
				if (ret >= 0)
								ret = cpy_to_user(buf, tmp, count) ? -EFAULT : ret;
				free(tmp);
read_out:	
				return ret;
}

static ssize_t spidev_write(struct file *file, const char *buf, size_t count,
								loff_t * offset)
{
				int ret = 0;
				char *tmp;
				struct spi_adapter *adap = (struct spi_adapter *)file->private_data;
//#ifdef DEBUG
				struct inode *inode = file->f_dentry->d_inode;
//#endif
				unsigned long (*cpy_from_user) (void *to, const void *from_user,
												unsigned long len);
				void *(*alloc) (size_t, int);
				void (*free) (const void *);

				if (count > SPI_TRANSFER_MAX)
								count = SPI_TRANSFER_MAX;

				cpy_from_user =
								adap->copy_from_user ? adap->copy_from_user : copy_from_user;
				alloc = adap->alloc ? adap->alloc : kmalloc;
				free = adap->free ? adap->free : kfree;

				/* copy user space data to kernel space. */
				tmp = alloc(count, GFP_KERNEL);
				if (tmp == NULL) {
								ret =  -ENOMEM;
								goto write_out_1;
				}

				if (cpy_from_user(tmp, buf, count)) {
								ret = -EFAULT;
								goto write_out_2;
				}

				printk ("spi-%d writing %zu bytes.\n", MINOR(inode->i_rdev), count);
				ret = spi_write(adap, 0, tmp, count);
write_out_2:	
				free(tmp);
write_out_1:	
				return ret;
}


typedef struct {
				unsigned int minor;
				struct file *file;
} spidev_openclose_t;

static int spidev_do_open(struct device *dev, void *context)
{
				spidev_openclose_t *o = (spidev_openclose_t *) context;
				struct spi_adapter *adap = SPI_ADAP(dev);
				spidev_driver_data_t *drvdata;
				int ret = 0;

				drvdata = (spidev_driver_data_t *) dev_get_drvdata(dev);
				if (NULL == drvdata) {
								pr_debug("%s: oops, drvdata is NULL !\n", __FUNCTION__);
								goto do_open_out;
				}

				pr_debug("drvdata->minor = %d vs %d\n", drvdata->minor, o->minor);
				if (drvdata->minor == o->minor) {
								get_device(&adap->dev);
								o->file->private_data = adap;
								ret = 1;
				}
do_open_out:
				return ret;
}
#endif

int spidev_open(struct inode *inode, struct file *file)
{
/*				spidev_openclose_t o;
				int status;

				o.minor = iminor(inode);
				o.file = file;
				status = driver_for_each_dev(&spidev_driver.driver, &o, spidev_do_open);
				if (status == 0) {
								status = -ENODEV;
				}
				return status < 0 ? status : 0;
*/

				printk (KERN_INFO "Open successful\n"); 
				return 0;
}

static int spidev_release(struct inode *inode, struct file *file)
{
				struct spi_adapter *adapter = file->private_data;

				if (adapter) {
								put_device(&adapter->dev);
				}
				file->private_data = NULL;

				return 0;
}

static int __init spi_dev_init(void)
{
				int ret = -ENODEV;
				int status;
				struct task_struct *get_pid1;

				printk(KERN_INFO "spi /dev entries driver\n");

				get_pid1 = current;
				printk( "current pid :%d\n", get_pid1 ->pid);

				// Allocation Device Numbers
				status = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);
				if(status < 0) {
								printk(KERN_NOTICE "Device number allocation failed: %d \n", status);
								goto err;
				} else {
								printk(KERN_NOTICE "Device number allocation SUCSESS");
				}

				majNo = MAJOR(mydev);

				printk(KERN_INFO "Major number allocated = %d \n", MAJOR(mydev));
				printk(KERN_INFO "Minor number allocated = %d \n", MINOR(mydev));
				my_cdev = cdev_alloc();	//Allocate memory for my_cdev
				if(my_cdev == NULL) {
								printk(KERN_ERR "cdev_alloc failed \n");
								goto err_cdev_alloc;
				} else {
								printk(KERN_ERR "cdev_alloc SUCSESS \n");
				}

				cdev_init(my_cdev, &fops);	//Initialize my_cdev with fops
				my_cdev->owner = THIS_MODULE;

				status = cdev_add(my_cdev, mydev, NR_DEVS);	//Add my_cdev to the list
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

				if (0 != (ret = spi_add_driver(&spidev_driver))) {
								goto err_device_create;
				}

#ifdef CONFIG_DEVFS_FS
				devfs_mk_dir("spi");
#endif
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

static void spidev_cleanup(void)
{
				spi_del_driver(&spidev_driver);
#ifdef CONFIG_DEVFS_FS
				devfs_remove("spi");
#endif
				unregister_chrdev(majNo, "spi");
}

MODULE_DESCRIPTION("SPI /dev entries driver");
MODULE_LICENSE("GPL");

module_init(spi_dev_init);
module_exit(spidev_cleanup);
