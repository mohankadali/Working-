#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/sysfs.h>
#include <linux/mod_devicetable.h>
#include <linux/log2.h>
#include <linux/bitops.h>
#include <linux/jiffies.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/kobject.h>
#include <linux/proc_fs.h>
#include <linux/ioctl.h>


MODULE_DESCRIPTION("eeprom Client Driver");
MODULE_AUTHOR("venkatarao");
MODULE_LICENSE("GPL");
MODULE_INFO(intree,"Y");
#define devname "eeprom"

volatile int eeprom_value = 0;
struct user_info
{
int pos;
int count;
char buf[256];
};

struct kobject *kobj_ref;
struct eeprom_data {
	struct i2c_client *client;
	u8 *write_buff;
	u16 write_max;
	dev_t devt;
	struct cdev cdev;
	struct class *class;
};	

/*************** Sysfs Fuctions **********************/
static ssize_t sysfs_show(struct kobject *kobj, 
                struct kobj_attribute *attr, char *buf);
static ssize_t sysfs_store(struct kobject *kobj, 
                struct kobj_attribute *attr, char *buf, size_t count);

struct kobj_attribute eeprom_attr = __ATTR(eeprom_value, 0660, sysfs_show, sysfs_store);

static ssize_t sysfs_show(struct kobject *kobj, 
                struct kobj_attribute *attr, char *buf)
{
        printk(KERN_INFO "Sysfs - Read!!!\n");
        return sprintf(buf, "%d", eeprom_value);
}

static ssize_t sysfs_store(struct kobject *kobj, 
                struct kobj_attribute *attr, char *buf, size_t count)
{
        printk(KERN_INFO "Sysfs - Write!!!\n");
        sscanf(buf,"%d",&eeprom_value);
        return count;
}
/*****************sysfs completed******************/ 


////*************procfs functions*************/
char eeprom_array[20]="try_proc_array\n";
static int proclen = 1;

static ssize_t read_proc(struct file *filp, char __user *buffer, size_t length,loff_t * offset)
{
    printk(KERN_INFO "proc file read.....\n");
    if(proclen)
        proclen=0;
    else{
        proclen=1;
        return 0;
    }
    copy_to_user(buffer,eeprom_array,20);
 
    return length;;
}
static ssize_t write_proc(struct file *filp, const char *buff, size_t len, loff_t * off)
{
    printk(KERN_INFO "proc file write.....\t");
    copy_from_user(eeprom_array,buff,len);
    return len;
}

static int open_proc(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "proc file opend.....\t");
    return 0;
}
 
static int release_proc(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "proc file released.....\n");
    return 0;
}

static struct file_operations proc_fops = {
    .open = open_proc,
    .read = read_proc,
    .write = write_proc,
    .release = release_proc
};

/*****************procfs completed******************/ 

static ssize_t eeprom_read(struct file* file, char *buf, size_t count, loff_t *pos) 
{
	struct i2c_msg msg[2];
	char *tmp;
	char *buf2;
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	int ret;
	printk(KERN_INFO "read started\n");
	if (count > 256)
	{
	printk(KERN_ERR "Error:reading the more than device size\n");
	return 0;
	
	}
	buf2 = kmalloc(1, GFP_KERNEL);
	if (buf2 == NULL)
	  return -ENOMEM;
	tmp = kmalloc(count, GFP_KERNEL);
	if (tmp == NULL)
	  return -ENOMEM;
	*buf2=0;

	msg[0].addr = 0x50; 
	msg[0].flags = 0x0000; 
	msg[0].len = 1;
	msg[0].buf = buf2;
	
	msg[1].addr = 0x50; 
	msg[1].flags = 0x0001; 
	msg[1].len = count;
	msg[1].buf = tmp;
	msleep(2);
	ret = i2c_transfer(adap, &msg, 2);
  
	if (ret < 0)
	{
	printk(KERN_ERR "Error: data read from device failed\n");
 
	}

	else	
	ret = copy_to_user(buf, tmp, count) ? -EFAULT : count;
	kfree(tmp);
	kfree(buf2);
	printk(KERN_INFO "\nread completed\n");	
	return ret;
}
static ssize_t eeprom_write(struct file* file, const char *buf, size_t count, loff_t *pos)
{
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	char *tmp;
	struct i2c_msg msg;
	char *buf2;
	int ret,cnt;
        int k=0x00,i;
	printk(KERN_INFO "write started\n");

        if (count > 256)
	{	
	printk(KERN_ERR "Error:no /sys/kernel/eeprom_sysfsfree space for writing lorge data\n");
	return 0;
	}
	buf2 = kmalloc(9, GFP_KERNEL);
	if (buf2 == NULL)
	  return -ENOMEM;
     	tmp = kmalloc(count, GFP_KERNEL);
	printk(KERN_INFO " temp count  %d",count);  
     	if (tmp == NULL)
		return -ENOMEM;

	tmp = memdup_user(buf, count);
	
	printk(KERN_INFO " user count  %d",count); 
	if (IS_ERR(tmp))
	return PTR_ERR(tmp);
        while(count>k)
	{
	for(i=0;i<9;i++)
		{
		if(i==0)
		*(buf2+i)=k;
		else
		*(buf2+i)=*(tmp++);
		}

	msg.addr = 0x50; 
	msg.flags = 0x0000; 
	msg.len =9;
	msg.buf = buf2;
	msleep(1);
     	ret = i2c_transfer(adap, &msg,1); 
        if(ret<0)
        printk(KERN_ERR "error: write tranfer 2222\n");
	k=k+8;
	//count=count-8;
	}
 	kfree(tmp);
	kfree(buf2);
	printk(KERN_INFO "write completed\n");
	return (ret == 1 ? count : ret);
}

//************ioctl implementartion**********************************////


static ssize_t eeprom_ioctl(struct file *file, int cmd, struct user_info *user)
{
	/*printk("input info CMD= %d",cmd);
	printk("input info count= %d",user->count);
	printk("input info pos= %d",user->pos);
	printk("input info buf= %s",user->buf);*/

	printk(KERN_INFO "ioctl started\n");
			//int ret;
	int pos=user->pos;
	struct i2c_msg msg[2];
	char *tmp;
	char *buf2;
	struct eeprom_data *dev = (struct eeprom_data *)(file->private_data);
	struct i2c_adapter *adap = dev->client->adapter;
	int ret,cnt,count;
        int k,i,len;
	count=user->count;
	cnt=user->count;
	printk(KERN_INFO "read started\n");
	printk(KERN_INFO "count=%d,pos=%d",count,pos);
	if (count > 256 || pos >= 256 || pos < 0 || count > (256-pos))
	{
	printk(KERN_ERR "Error:reading the more than device size\n");
	return -EINVAL;
	
	}
	buf2 = kmalloc(9, GFP_KERNEL);
	if (buf2 == NULL)
	  return -ENOMEM;
	tmp = kmalloc(count, GFP_KERNEL);
	if (tmp == NULL)
	  return -ENOMEM;

	switch(cmd)
	{
	case 0:
		
		k=pos;
		if(pos%8==0)
		{
		len=9;
		}
		else
		{
		//i=pos%8;
		len=(pos%8)+1;
		}
	ret=copy_from_user(tmp ,user->buf, count);
	if(ret != 0)
	{
    	printk(KERN_INFO " user input value  %d",ret); 
	break;	
	}
	//tmp = memdup_user(user->buf, count);
	printk(KERN_INFO " user count  %d",count); 
	//if (IS_ERR(tmp))
	//return PTR_ERR(tmp);
        while(cnt > 0)
	{
	for(i=0;i<len;i++)
		{
		if(i==0)
		*(buf2+i)=k;
		else
		*(buf2+i)=*(tmp++);
		}

	msg[0].addr = 0x50; 
	msg[0].flags = 0x0000; 
	msg[0].len =len;
	msg[0].buf = buf2;
 
	msleep(1);
     	ret = i2c_transfer(adap, &msg,1);
	printk(KERN_INFO " write i2c transfer return value  %d",ret); 
        if(ret<0)
        printk(KERN_ERR "error: write tranfer 2222\n");
	k=k+(len-1);
	len=9;
	cnt=cnt-8;
	}

	break;
	case 1:

		*buf2=pos;
		msg[0].addr = 0x50; 
		msg[0].flags = 0x0000; 
		msg[0].len = 1;
		msg[0].buf = buf2;
	
		msg[1].addr = 0x50; 
		msg[1].flags = 0x0001; 
		msg[1].len = count;
		msg[1].buf = tmp;
		msleep(2);
		ret = i2c_transfer(adap, &msg, 2);
	  	printk(KERN_INFO " read i2c transfer return value  %d",ret);
		if (ret < 0)
		{
			printk(KERN_ERR "Error: data read from device failed\n");
			break;
		} else {

		ret = copy_to_user(user->buf, tmp, count);// ? -EFAULT : count;
		printk(KERN_INFO " read copy to user return value  %d",ret);
		if (ret < 0)
			break;
		}

	break;
	default:
		ret=-1;
	break;
	}

	kfree(tmp);
	kfree(buf2);
	printk(KERN_INFO "ioctl completed\n");
	return ret;

}

///************************ioctl completed***********************************************////
static int eeprom_open(struct inode *inode, struct file *file)
{
	struct eeprom_data *dev = container_of(inode->i_cdev, struct eeprom_data, cdev);
	if (dev == NULL) {
		printk(KERN_ERR "Error: open failed\n");
		return -1;
	}
	file->private_data = dev;

	return 0;
}

static int eeprom_close(struct inode *inode, struct file *file)
{
	return 0;
}

struct file_operations fops = {
	.open = eeprom_open,
	.release = eeprom_close,
	.read = eeprom_read,
	.write = eeprom_write,
	.unlocked_ioctl = eeprom_ioctl,
};

static int eeprom_remove(struct i2c_client *client)
{
	printk(KERN_INFO "Remove started\n");
	struct eeprom_data *dev;
	dev = i2c_get_clientdata(client);
	remove_proc_entry("eeprom_proc",NULL);
        sysfs_remove_file(kernel_kobj, &eeprom_attr.attr);   
	kobject_put(kobj_ref); 
	cdev_del(&dev->cdev);
	device_destroy(dev->class, dev->devt);
	class_destroy(dev->class);
	unregister_chrdev_region(dev->devt, 1);
	printk(KERN_INFO "Remove completed\n");
	return 0;

}
static int eeprom_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	printk(KERN_INFO "Probe started\n");
	struct eeprom_data *data;
	int init_result;
	data = devm_kzalloc(&client->dev,sizeof(struct eeprom_data), GFP_KERNEL);
	data->write_max = 32;
	data->write_buff = devm_kzalloc(&client->dev, data->write_max, GFP_KERNEL);
	i2c_set_clientdata(client, data);
	init_result = alloc_chrdev_region(&data->devt, 0, 1, "eeprom");
	data->client = client;

	if( 0 > init_result )
	{
	printk(KERN_ERR "Error:Device Registration failed\n");
	return -1;
	}
	printk(KERN_INFO "Major Nr: %d\n", MAJOR(data->devt));

	if ((data->class = class_create(THIS_MODULE, "eeprom")) == NULL)
	{
	printk(KERN_ALERT "Error:class creat faileed\n");
	return -1;
	}
	if(device_create(data->class, NULL, data->devt, NULL, "eeprom") == NULL)
	{
	printk(KERN_ALERT "Error:device create faileed\n");
	return -1;
	}

	cdev_init(&data->cdev, &fops);

	if(cdev_add(&data->cdev, data->devt, 1) <0)
	{
	printk(KERN_ERR "Error:cdev add faileed\n");
	return -1;
	}
	
	kobj_ref = kobject_create_and_add("eeprom_sysfs",kernel_kobj);
	if(kobj_ref==NULL)
	{
	printk(KERN_ERR "Error:Kobject creation faileed\n");
	}

	if(sysfs_create_file(kobj_ref,&eeprom_attr.attr))
	{
	printk(KERN_INFO"Cannot create sysfs file......\n");
        sysfs_remove_file(kernel_kobj, &eeprom_attr.attr);   
	kobject_put(kobj_ref); 
        
    	}
	
		
	proc_create("eeprom_proc",0666,NULL,&proc_fops);

	printk(KERN_INFO "Probe completed\n");
	return 0;
}

static const struct i2c_device_id eeprom_ids[] = {
	//{ 0x50, 0},
	{ devname, 0},
	{ }
};
MODULE_DEVICE_TABLE(i2c, eeprom_ids);

static struct i2c_driver eeprom_driver = {
	.driver = {
		.name = "eeprom",
		.owner = THIS_MODULE,
	},
	.probe = eeprom_probe,
	.remove = eeprom_remove,
	.id_table = eeprom_ids,
};

static int __init eeprom_init(void)
{
return i2c_add_driver(&eeprom_driver);
}

static void __exit eeprom_exit(void)
{
i2c_del_driver(&eeprom_driver);
}

module_init(eeprom_init);
module_exit(eeprom_exit);



