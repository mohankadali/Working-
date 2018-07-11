
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

#define FIRST_MINOR 0
#define NR_DEV 1          /*number of device number */

/* define your own my_function call */

/*function declaration for sys call declarations */

extern long my_ps (struct file *  , unsigned  int, long unsigned  );
extern int my_Open  (struct inode * , struct file * );
extern int my_Release (struct inode * , struct  file * );


/*intialization of routines */

static int my_Init (void);
static void my_Exit (void);

struct file_operations fops = {
.owner = THIS_MODULE,
.open = my_Open ,
.release = my_Release,
.unlocked_ioctl = my_ps 
};

/*global  variables */

char * devname ;
int mejNo ;              // encodes mejor number and min number 
static dev_t mydev ;
struct cdev* my_cdev ;  // holds char device driver descriptor 

/* to accepts input from cammand line */
module_param (devname , charp ,0000);

/*class device structure */
static struct class * mychar_class ;
static struct device *mychar_device ;



/*my_init : init function of kernel modules*/

static int __init my_Init (void)
{
	int ret = -ENODEV;
	int status ;
	
	printk (KERN_INFO  "initializinng charector device  \n");
	
	/*allocating device number */

	status = alloc_chrdev_region (&mydev , FIRST_MINOR , NR_DEV, devname);
	if ( status < 0) {
	printk (KERN_NOTICE  "Device number allocation failed_%d\n", status );
	goto err ;
	}
	
	printk (KERN_INFO  "Device number allocated %d\n", MAJOR(mydev) );	
	my_cdev = cdev_alloc (); /*allocate memory for  my dev*/

	if (NULL == my_cdev ) {
	printk (KERN_ERR  "Device number allocated %d\n", MAJOR(mydev) );
	goto err_cdev_alloc ;
	}

	cdev_init (my_cdev,&fops); /*initialization of my_cdev with fops */
	my_cdev ->owner = THIS_MODULE;
	status = cdev_add (my_cdev , mydev, NR_DEV); 
	/* add my cdev to  the list */
	
	if (status ) {	
	printk (KERN_ERR  "cdev failed \n ");
	goto err_cdev_add ;
	}

	/* create a class and system entry in sys fs */

	mychar_class = class_create (THIS_MODULE , devname);
	if(IS_ERR( mychar_class) ) {
	printk (KERN_ERR  "Class create fauiled ");
	goto err_class_create;
	}
	
	/*create char device in sys fs and an device entry will be made in dev directory */
	mychar_device = device_create (mychar_class, NULL ,mydev , NULL , devname );
	if ( IS_ERR ( mychar_device)) {	
	printk (KERN_ERR  "Device create failed\n"  );
	goto err_device_create ;
	}	
	return 0;

err_device_create : 
	class_destroy ( mychar_class ) ;
err_class_create :
	cdev_del ( my_cdev ) ;
err_cdev_add :
	kfree (my_cdev) ;
err_cdev_alloc : 
	unregister_chrdev_region (mydev , NR_DEV);
err : 
	return ret;
}

	/*my exit : clean up function  of kernel modules */
static void my_Exit ( void ) 
{
	printk (KERN_INFO  "Exiting the char device\n "  );
	device_destroy (mychar_class , mydev);
	class_destroy (mychar_class);
	cdev_del (my_cdev);
	unregister_chrdev_region (mydev , NR_DEV);
	return ;  
}
	

module_init (my_Init);
module_exit (my_Exit);

