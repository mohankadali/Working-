
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
#include <linux/pid.h>
#include <linux/rculist.h> 

MODULE_LICENSE("Dual BSD/GPL");

/*my_ioctl function to print the process id of process &  psudo  driver  */

long my_ps (struct file * fp , unsigned int pid , long unsigned ppid )
{
     struct task_struct *p = current  ; 
     struct signal_struct *sptr ;   
     
     if ( p->signal ) {
         sptr = p->signal->tty->session->driver->name ; 
     } else { 
         sptr = NULL ; 
     } 

     printk (KERN_CONT "PID      TTY     TIME     CMD ") ; 
     printk (KERN_CONT "%d%10.2llu%10s "   ,p->pid, p->stime , sptr, p->cmd) ;   
       
        return 0;
}

EXPORT_SYMBOL (my_ps);	
