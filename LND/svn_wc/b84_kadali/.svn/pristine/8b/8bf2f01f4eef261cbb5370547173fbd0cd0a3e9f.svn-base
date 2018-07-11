
/* programm to understand the fork behavior on local data */


/*
 * conclusion : 
 *
 * in the fork system  call : 
 * parent and child both share the same local variable 
 * 1. in heap  
 * 2. in stack ( const , volatile and all variable ) 
 * 3. if there is no wait system call any statment can be executed first 
 * 4. in execution of statement  guaranteed that child will execute first
 * parent is blocked untill child complete their job 
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
    int fd ;

    fd = open ("/dev/my_vfork", O_RDWR) ; /*openn file to print addr in kernel space  */


    local_ptr = malloc (sizeof (int)*15 ) ;
    *local_ptr  = 60 ;
        
    pid_t = vfork() ;

    switch ( pid_t  ) { 
        case -1 : 

            printf ("fail to create a new process\n");
            exit (0) ;
            break ; 

        case  0 : 

        printf ("child pid                : %d\n" , getpid ()) ;
        printf ("child_local var          : %d\n" , local_var  );
        printf ("child_local var_addr     : %p\n" , &local_var  );
        printf ("child_local_var_init     : %d\n" , local_var_init );
        printf ("child_local var_init_addr: %p\n" , &local_var_init );
        printf ("child_local_ptr          : %d\n" , *local_ptr );
        printf ("child_local var_ptr      : %p\n" , local_ptr );
        printf ("child_local_const        : %d\n" , local_const ); 
        printf ("child_local_const_addr   : %p\n" , &local_const );
        printf ("child_local_volatile     : %d\n" , local_volatile );
        printf ("child_local_volatile_addr: %p\n" , &local_volatile );
        
        printf ("calling to ioctl function to varify the data and code addr at kernel  space \n"); 
        
        ioctl ( fd , getpid() , getppid() ) ; 

        printf ("exiting from child process______\n\n\n");
        exit (0) ; 
    
        break ;

        default :

     local_var  = 100  ;                      /*local variable under experimant */
     local_var_init = 200 ;             /* init var under fork experiment */
     *local_ptr = 300  ;                     /*heap data in experimant   */
     local_volatile = 400 ;    /*stack data in expeimant  */

        printf ("parent_parentpid          : %d\n" , getpid ()) ;
        printf ("parent_local var          : %d\n" , local_var  );
        printf ("parent_local var_addr     : %p\n" , &local_var  );
        printf ("parent_local_var_init     : %d\n" , local_var_init );
        printf ("parent_local var_init_addr: %p\n" , &local_var_init );
        printf ("parent_local_ptr          : %d\n" , *local_ptr );
        printf ("parent_local var_ptr      : %p\n" , local_ptr );
        printf ("parent_local_const        : %d\n" , local_const ); 
        printf ("parent_local_const_addr   : %p\n" , &local_const );
        printf ("parent_local_volatile     : %d\n" , local_volatile );
        printf ("parent_local_volatile_addr: %p\n" , &local_volatile );
        printf ("calling to ioctl function to varify the data and code addr at kernel space\n"); 
        
        ioctl ( fd , getpid() , getppid() ) ; 

        printf ("exiting from parent process______\n\n\n");

    } 

    return 0; 
}
   

    
     

     

