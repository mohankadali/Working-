
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
#include <linux/mm.h>
#include <linux/file.h>
#include <linux/fdtable.h>

MODULE_LICENSE("Dual BSD/GPL");

/*my_ioctl function to print the process id of process &  psudo  driver  */

long my_vfork (struct file * fp , unsigned int pid , long unsigned ppid )
{
     struct task_struct *p = current  ; 

     printk (KERN_CONT "Addr (VFS)  of child and parent  :%p\n "  , p->files->fdt->fd[3] ) ;   
    /*print the VFS data structure address associates with file descreptor  */ 
     printk (KERN_CONT "fd shared by process count:%d\n "  , p->files->fdt->fd[3]->f_count.counter ) ; 
     /*peint how many process  is sharing this file discreptor  */   
     printk (KERN_CONT " process  id              :%u\n "  , pid  ) ; 
     printk (KERN_CONT " process  parent          :%ld\n"  , ppid ) ; 
       
        return 0;
}

EXPORT_SYMBOL (my_vfork);	
