
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/gpio.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <uapi/asm-generic/errno-base.h>
#include <linux/string.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/time.h>

/* User-defined macros */
#define NUM_GPIO_PINS 21
#define MAX_GPIO_NUMBER32
#define DEVICE_NAME "raspi-gpio"
#define BUF_SIZE 512
#define MAX_GPIO_NUMBER 4
#define INTERRUPT_DEVICE_NAME "gpio interrupt"

/* User-defined data types */
enum state {low, high};
enum direction {in, out};

struct raspi_gpio_dev {
        struct cdev cdev;
        struct gpio pin;
        enum state state;
        enum direction dir;
        bool irq_perm;
        unsigned long irq_flag;
        unsigned int irq_counter;
        spinlock_t lock;
};



/* Declaration of entry points */
static int raspi_gpio_open(struct inode *inode, struct file *filp);
static ssize_t raspi_gpio_read (struct file *filp, char *buf, size_t count, loff_t *f_pos);
static ssize_t raspi_gpio_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int raspi_gpio_release(struct inode *inode, struct file *filp);
/* File operation structure */


static struct file_operations raspi_gpio_fops = {
        .owner = THIS_MODULE,
        .open=raspi_gpio_open,
        .release=raspi_gpio_release,
        .read= raspi_gpio_read,
        .write= raspi_gpio_write,
};

/* Forward declaration of functions */
static int raspi_gpio_init(void);

//static void raspi_gpio_exit(void);
unsigned int millis (void);

static irqreturn_t irq_handler(int , void *);


/* Global varibles for GPIO driver */
struct raspi_gpio_dev *raspi_gpio_devp[NUM_GPIO_PINS];
static dev_t first;
static struct class *raspi_gpio_class;
static unsigned int last_interrupt_time = 0;
static uint64_t epochMilli;



unsigned int millis (void)
{
        struct timeval timeval ;
        uint64_t timeNow ;
        do_gettimeofday(&timeval) ;

        timeNow=(uint64_t)timeval.tv_sec * (uint64_t)1000 + (uint64_t)(timeval.tv_usec/1000);
        return (uint32_t)(timeNow -epochMilli) ;
}

static irqreturn_t irq_handler(int irq, void *arg) {
        unsigned long flags;
        unsigned int interrupt_time = millis();
        if (interrupt_time -last_interrupt_time < 200) {
                printk(KERN_NOTICE "Ignored Interrupt [%d]\n", irq);
                return IRQ_HANDLED;
        }
        last_interrupt_time = interrupt_time;
        local_irq_save(flags);
        printk(KERN_NOTICE "Interrupt [%d] was triggered\n", irq);
        local_irq_restore(flags);
        return IRQ_HANDLED;
}


static int raspi_gpio_open (struct inode *inode, struct file *filp) {
        struct raspi_gpio_dev *raspi_gpio_devp;
        unsigned int gpio;
        int err, irq;
        unsigned long flags;
        gpio = iminor(inode);
        printk(KERN_INFO "GPIO[%d] opened\n", gpio);
        raspi_gpio_devp = container_of(inode->i_cdev, struct raspi_gpio_dev,cdev);
        if ((raspi_gpio_devp->irq_perm == true) && (raspi_gpio_devp->dir == in)) 
        {
                if ((raspi_gpio_devp->irq_counter++ == 0)) {
                        irq = gpio_to_irq(gpio);
                        if (raspi_gpio_devp->irq_flag == IRQF_TRIGGER_RISING) 
                        {
                                spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                                err = request_irq(
                                                irq,
                                                irq_handler,
                                                IRQF_SHARED | IRQF_TRIGGER_RISING,
                                                INTERRUPT_DEVICE_NAME,
                                                raspi_gpio_devp);
                                printk(KERN_INFO "interrupt requested\n");
                                spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
                        } else {
                                spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                                err = request_irq
                                        (
                                         irq,
                                         irq_handler,
                                         IRQF_SHARED | IRQF_TRIGGER_FALLING,
                                         INTERRUPT_DEVICE_NAME,
                                         raspi_gpio_devp);
                                printk(KERN_INFO "interrupt requested\n");
                                spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
                        }
                        if (err != 0) {
                                printk(KERN_ERR "unable to claim irq: %d, error %d\n", irq,err);
                                return err;
                        }
                }
        }
        filp->private_data = raspi_gpio_devp;
        return 0;
}






static int raspi_gpio_release (struct inode *inode, struct file *filp)
{
        unsigned int gpio;
        struct raspi_gpio_dev *raspi_gpio_devp;
        raspi_gpio_devp = container_of(inode->i_cdev, 
                        struct raspi_gpio_dev,cdev);
        gpio = iminor(inode);
        printk(KERN_INFO "Closing GPIO %d\n", gpio);
        spin_lock(&raspi_gpio_devp->lock);
        if (raspi_gpio_devp->irq_perm == true) {
                if (raspi_gpio_devp->irq_counter > 0) {
                        raspi_gpio_devp->irq_counter--;
                        if (raspi_gpio_devp->irq_counter == 0) {
                                printk(KERN_INFO "interrupt on gpio[%d] released\n", gpio);
                                free_irq(gpio_to_irq(gpio), raspi_gpio_devp);
                        }
                }
        }
        spin_unlock(&raspi_gpio_devp->lock);
        if (raspi_gpio_devp->irq_perm == false && raspi_gpio_devp->irq_counter > 0) {
                spin_lock(&raspi_gpio_devp->lock);
                free_irq(gpio_to_irq(gpio), raspi_gpio_devp);
                raspi_gpio_devp->irq_counter = 0;
                spin_unlock(&raspi_gpio_devp->lock);
                printk(KERN_INFO "interrupt on gpio[%d] disabled\n", gpio);
        }
        return 0;
}



static ssize_t raspi_gpio_read (struct file *filp,char *buf,size_t count,loff_t *f_pos)
{
        unsigned int gpio;
        ssize_t retval;
        char byte;
        gpio = iminor(filp->f_path.dentry->d_inode);
        for (retval = 0; retval < count; ++retval) {
                byte = '0' + gpio_get_value(gpio);
                if(put_user(byte, buf+retval))
                        break;
        }
        return retval;
}










static ssize_t raspi_gpio_write (struct file *filp,const char *buf,size_t count,loff_t *f_pos)
{
        unsigned int gpio, len = 0, value = 0;
        char kbuf[BUF_SIZE];
        struct raspi_gpio_dev *raspi_gpio_devp = filp->private_data;
        unsigned long flags;
        gpio = iminor(filp->f_path.dentry->d_inode);
        len = count < BUF_SIZE ? count-1 : BUF_SIZE-1;
        //if(copy_from_user(kbuf, buf, len) != 0)
         //       return -EFAULT;
        kbuf[len] = '\0';
        printk(KERN_INFO "Request from user: %s\n", kbuf);
        // Check the content of kbuf and set GPIO pin accordingly
        if (strcmp(kbuf, "out") == 0) {
                printk(KERN_ALERT "gpio[%d] direction set to ouput\n", gpio);
                if (raspi_gpio_devp->dir != out) {
                        spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                        gpio_direction_output(gpio, low);
                        raspi_gpio_devp->dir = out;
                        raspi_gpio_devp->state = low;
                        spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
                }
        } else if (strcmp(kbuf, "in") == 0) {
                if (raspi_gpio_devp->dir != in) {
                        printk(KERN_INFO "Set gpio[%d] direction: input\n", gpio);
                        spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                        gpio_direction_input(gpio);
                        raspi_gpio_devp->dir = in;
                        spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
                }
        } else if ((strcmp(kbuf, "1") == 0) || (strcmp(kbuf, "0") == 0)) {
                sscanf(kbuf, "%d", &value);
                if (raspi_gpio_devp->dir == in) {
                        printk("Cannot set GPIO %d, direction: input\n", gpio);
                        return -EPERM;
                }
                if (raspi_gpio_devp->dir == out) {
                        if (value > 0) {
                                spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                                gpio_set_value(gpio, high);
                                raspi_gpio_devp->state = high;
                                spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
                        } else {
                                spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                                gpio_set_value(gpio, low);
                                raspi_gpio_devp->state = low;
                                spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
                        }
                }
        } else if ((strcmp(kbuf, "rising") == 0) || (strcmp(kbuf, "falling")== 0)) {
                spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                gpio_direction_input(gpio);
                raspi_gpio_devp->dir = in;
                raspi_gpio_devp->irq_perm = true;
                if (strcmp(kbuf, "rising") == 0)
                        raspi_gpio_devp->irq_flag = IRQF_TRIGGER_RISING;
                else 
                        raspi_gpio_devp->irq_flag = IRQF_TRIGGER_FALLING;
                spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
        } else if (strcmp(kbuf, "disable-irq") == 0){
                spin_lock_irqsave(&raspi_gpio_devp->lock, flags);
                raspi_gpio_devp->irq_perm = false;
                spin_unlock_irqrestore(&raspi_gpio_devp->lock, flags);
        } else {
                printk(KERN_ERR "Invalid value\n");
                return -EINVAL;
        }
        *f_pos += count;
        return count;
}

static int __init raspi_gpio_init(void)
{
        printk(KERN_DEBUG "MOHAN GPIO register device\n");
        int i, ret, index = 0;
        struct timeval tv ;
        if (alloc_chrdev_region(&first, 0, NUM_GPIO_PINS, DEVICE_NAME) < 0) {
                printk(KERN_DEBUG "Cannot register device\n");
                return -1;
        }
        if ((raspi_gpio_class = class_create(THIS_MODULE, DEVICE_NAME)) == NULL) {
                printk(KERN_DEBUG "Cannot create class %s\n", DEVICE_NAME);
                unregister_chrdev_region(first, NUM_GPIO_PINS);
                return -EINVAL;
        }


        for (i = 0; i < MAX_GPIO_NUMBER; i++) {
                if (i != 0 && i != 1 && i != 5 && i != 6 &&
                                i != 12 && i != 13 && i != 16 && i != 19 &&
                                i != 20 && i != 21 && i != 26) {
                        raspi_gpio_devp[index] = kmalloc(sizeof(struct raspi_gpio_dev),GFP_KERNEL);
                        if (!raspi_gpio_devp[index]) {printk("Bad kmalloc\n");
                                return -ENOMEM;
                        }
                        if (gpio_request_one(i, GPIOF_OUT_INIT_LOW, NULL) < 0) {
                                printk(KERN_ALERT "Error requesting GPIO %d\n", i);
                                return -ENODEV;
                        }
                        raspi_gpio_devp[index]->dir = out;
                        raspi_gpio_devp[index]->state = low;
                        raspi_gpio_devp[index]->irq_perm = false;
                        raspi_gpio_devp[index]->irq_flag = IRQF_TRIGGER_RISING;
                        raspi_gpio_devp[index]->irq_counter = 0;
                        raspi_gpio_devp[index]->cdev.owner = THIS_MODULE;
                        spin_lock_init(&raspi_gpio_devp[index]->lock);
                        cdev_init(&raspi_gpio_devp[index]->cdev, &raspi_gpio_fops);
                        if ((ret = cdev_add(&raspi_gpio_devp[index]->cdev, (first + i), 1))) {
                                printk (KERN_ALERT "Error %d adding cdev\n", ret);
                                for (i = 0; i < MAX_GPIO_NUMBER; i++) {
                                        if (i != 0 && i != 1 && i != 5 && i != 6 &&
                                                        i != 12 && i != 13 && i != 16 && 
                                                        i != 19 &&
                                                        i != 20 && i != 21 && i != 26) {
                                                device_destroy (raspi_gpio_class,MKDEV(MAJOR(first),MINOR(first) + i));
                                        }
                                }
                                class_destroy(raspi_gpio_class);
                                unregister_chrdev_region(first, NUM_GPIO_PINS);
                                return ret;
                        }

                        if (device_create(raspi_gpio_class,NULL,MKDEV(MAJOR(first), MINOR(first)+i),NULL,"raspiGpio%d",i) == NULL) {
                                class_destroy(raspi_gpio_class);
                                unregister_chrdev_region(first, NUM_GPIO_PINS);
                                return -1;
                        }
                        index++;
                }
        }
        // Configure interrupt
        do_gettimeofday(&tv) ;
        epochMilli =(uint64_t)tv.tv_sec *(uint64_t)1000 +(uint64_t)(tv.tv_usec/1000);
        printk("RaspberryPi GPIO driver initialized\n");
        return 0;
}


static void __exit raspi_gpio_exit(void)
{
        int i = 0;
        unregister_chrdev_region(first, NUM_GPIO_PINS);
        for(i = 0; i < NUM_GPIO_PINS; i++)
                kfree(raspi_gpio_devp[i]);
        for (i = 0; i < MAX_GPIO_NUMBER; i++) {
                if (            i != 0 && i != 1 && i != 5 && i != 6 &&
                                i != 12 && i != 13 && i != 16 && i != 19 &&
                                i != 20 && i != 21 && i != 26) {
                        gpio_direction_output(i, 0);
                        device_destroy (raspi_gpio_class,MKDEV(MAJOR(first), MINOR(first) + i));
                        gpio_free(i);
                }
        }
        class_destroy(raspi_gpio_class);
        printk(KERN_INFO "RaspberryPi GPIO driver removed\n");
}
module_init(raspi_gpio_init);
module_exit(raspi_gpio_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vu Nguyen <quangngmetro@gmail.com>");
MODULE_DESCRIPTION("GPIO device driver for Raspberry Pi B rev2 platform"); 




