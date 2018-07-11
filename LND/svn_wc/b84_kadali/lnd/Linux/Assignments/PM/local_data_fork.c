
/* programm to understand the fork behavior on local data */


/*
 * conclusion : 
 *
 * in the fork system  call : 
 * parent and child both share the same local variable 
 * 1. in heap  
 * 2. in stack ( const , volatile and all variable ) 
 * 3. if there is no wait system call any statment can be executed first 
 * 4. in execution of statement no guaranteed that which statment will 
 * execute execution can be one from parent and one from child or more 
 * then one statment 
 * wait system call is only for wait the child state change determined 
 * by parent  
 *
 * */

#include "fork.h"

int local_var_experiment (void)
{
    int local_var  ;                      /*local variable under experimant */
    int local_var_init = 30 ;             /* init var under fork experiment */
    int *local_ptr  ;                     /*heap data in experimant   */
    int const local_const = 25 ;          /*stack data in expermant  */
    int volatile local_volatile = 70 ;    /*stack data in expeimant  */
    int pid_t  ;
    int status ; 
    int fd ; 
    fd = open ("/dev/my_vfork", O_RDWR ) ; 

    local_ptr = malloc (sizeof (int)*15 ) ;
    *local_ptr  = 60 ;

    if(!( pid_t = vfork() ) )
    { 
    

        printf ("hild pid                    : %d\n" , getpid ()) ;
        printf ("hild_local var              : %d\n" , local_var  );
        printf ("hild_local var_addr         : %p\n" , &local_var  );
        printf ("hild_local_var_init         : %d\n" , local_var_init );
        printf ("hild_local var_init_addr    : %p\n" , &local_var_init );
        printf ("hild_local_ptr              : %d\n" , *local_ptr );
        printf ("hild_local var_ptr          : %p\n" , local_ptr );
        printf ("hild_local_const            : %d\n" , local_const ); 
        printf ("hild_local_const_addr       : %p\n" , &local_const );
        printf ("hild_local_volatile         : %d\n" , local_volatile );
        printf ("hild_local_volatile_addr    : %p\n" , &local_volatile );
//        printf ("calling to ioctl function \n\n\n");

//        ioctl (fd , getpid() , getppid () ) ;
//        close ( fd ) ;

        printf ("******exiting from child process******\n\n\n");
        exit (0) ; 
    }
    else
    {



        printf ("arent_pid                     : %d\n" , getpid ()) ;
        printf ("arent_local var               : %d\n" , local_var  );
        printf ("arent_local var_addr          : %p\n" , &local_var  );
        printf ("arent_local_var_init          : %d\n" , local_var_init );
        printf ("arent_local var_init_addr     : %p\n" , &local_var_init );
        printf ("arent_local_ptr               : %d\n" , *local_ptr );
        printf ("arent_local var_ptr           : %p\n" , local_ptr );
        printf ("arent_local_const             : %d\n" , local_const ); 
        printf ("arent_local_const_addr        : %p\n" , &local_const );
        printf ("arent_local_volatile          : %d\n" , local_volatile );
        printf ("arent_local_volatile_addr     : %p\n" , &local_volatile );
//        printf ("calling to ioctl function \n\n\n");

  //      ioctl (fd , getpid() , getppid () ) ;
    //    close ( fd ) ;
        printf ("*******exiting from parent process******_\n\n\n");
wait(0);
    } 
    return 0; 
}

