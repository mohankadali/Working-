
 #include <linux/init.h>                                                         
 #include <linux/module.h>                                                       
 #include <linux/fs.h>                                                           
 #include <linux/sched.h>                                                        
 #include <linux/cdev.h>                                                         
 #include <asm/uaccess.h>                                                        
 #include <linux/device.h>                                                       
 #include <linux/slab.h> 


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/fb.h>
#include <linux/init.h>
#include <linux/pci.h>
#include "intelfb.h"
#include "intelfbhw.h"
MODULE_LICENSE("Dual BSD/GPL") ; 
 #define FIRST_MINOR 11                                                          
 #define NR_DEVS 1 //Number of device numbers       


char *devname ; //contains device name                                          
int majNo ;                                                                     
static dev_t mydev ; //encodes major number & minor number device               
struct cdev *my_cdev ; //holds character device driver descriptor    

module_param(devname, charp, 0000) ;
 static struct class *mychar_class ;                                             
 static struct device *mychar_device ;



unsigned long addr, size;

static struct fb_ops ourfb_ops = {
    .owner = THIS_MODULE,
    .fb_fillrect = cfb_fillrect,
    .fb_imageblit = cfb_imageblit,
    .fb_copyarea = cfb_copyarea,
};


struct file_operations fops = {                                                 
    .owner = THIS_MODULE,                                                       
   // .open = myOpen,                                                             
   // .release = myRelease,                                                       
   // .unlocked_ioctl = myioctl                                                   
} ; 

static int ourfb_pci_init(struct pci_dev *dev, const struct pci_device_id *ent)
{
  int ret = -ENODEV ;                                                         
   int status ;                                                                
                                                                                
      //Allocating Device Numbers                                                 
                                                                                  
      status = alloc_chrdev_region ( &mydev, FIRST_MINOR, NR_DEVS, devname ) ;    
  my_cdev = cdev_alloc () ;
   cdev_init ( my_cdev, &fops ) ; //Initialize my_cdev with fops               
         my_cdev->owner = THIS_MODULE ;                                              
         status = cdev_add ( my_cdev, mydev, NR_DEVS ) ;
  mychar_class = class_create (THIS_MODULE, devname) ; 
   mychar_device = device_create ( mychar_class, NULL, mydev, NULL, devname ) ;



 

     struct fb_info *info;

struct ourfb_par *par;
    struct device *device = &dev->dev;
    //int cmap_len, retval;
    int cmap_len;
    info = framebuffer_alloc(sizeof(struct fb_info), device);
    if (!info) {
        return -ENOMEM;
    }
    par = info->par;
    info->fbops = &ourfb_ops;
    
    info->flags = FBINFO_DEFAULT;
    
    if (fb_alloc_cmap(&info->cmap, cmap_len, 0))
        return -ENOMEM;
    if (register_framebuffer(info) < 0) {
        fb_dealloc_cmap(&info->cmap);
        return -EINVAL;
    }
    pci_set_drvdata(dev, info);
    return 0;
}
static void ourfb_pci_remove(struct pci_dev *dp)
{
    struct fb_info *p = pci_get_drvdata(dp);
    unregister_framebuffer(p);
    fb_dealloc_cmap(&p->cmap);
    iounmap(p->screen_base);
    framebuffer_release(p);
    device_destroy ( mychar_class, mydev ) ;                                    
    class_destroy ( mychar_class ) ;                                            
    cdev_del ( my_cdev ) ;                                                      
    unregister_chrdev_region ( mydev, NR_DEVS ) ;                               
    return ;                                            


}








static struct pci_device_id ourfb_pci_tbl[] = {
     { PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_830M, PCI_ANY_ID, PCI_ANY_ID },
    { 0 }
};
MODULE_DEVICE_TABLE(pci, ourfb_pci_tbl);



static struct pci_driver ourfb_driver = {
    .name = "ourfb",
    .id_table = ourfb_pci_tbl,
    .probe = ourfb_pci_init,
    .remove = ourfb_pci_remove,
};



static int __init ourfb_init(void)
{
    return pci_register_driver(&ourfb_driver);
}
static void __exit ourfb_exit(void)
{
    pci_unregister_driver(&ourfb_driver);
}
module_init(ourfb_init);
module_exit(ourfb_exit);
MODULE_LICENSE("GPL");
