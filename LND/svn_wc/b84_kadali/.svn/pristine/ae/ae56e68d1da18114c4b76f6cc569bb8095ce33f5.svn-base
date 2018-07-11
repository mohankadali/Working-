
/* programm to understand the fork behavior on global data */


/*
 * conclusion : 
 *
 * in the vfork system  call : 
 * parent and child both share the same global variable 
 * 1. heap 
 * 2.data
 * 3.rodata
 * 4.bss
 * */

#include "fork.h"

    int global_var  ;                      /*global data under experiment */
    int global_var_init = 30 ;             /*init data under experiment  */
    int *global_ptr  ;                     /*global pointer in data */
    int const global_const = 25 ;          /*global data in ro section */
    int volatile global_volatile = 70 ;    /*global volatile is in data */
    int pid  ;                 



int global_var_experiment (void)
{
    
    int fd ; 
    
    fd = open ("/dev/my_vfork", O_RDWR )  ;
    if ( fd < 0 ) { 
        perror ("open");
        exit (0 ) ;
    } 

    global_ptr = malloc (sizeof (int)*15 ) ;
    *global_ptr  = 60 ;

    pid = vfork() ;

    switch ( pid  ) { 
        case -1 : 

            printf ("fail to create a new process\n");
            exit (0) ;
            break ; 

        case  0 : 
            /*in the case of child this code will execute fork return 0 on
             * succcessful child creation to the child  */

        printf ("child pid                 : %d\n" , getpid ()) ;
        printf ("child_global var          : %d\n" , global_var  );
        printf ("child_global var_addr     : %p\n" , &global_var  );
        printf ("child_global_var_init     : %d\n" , global_var_init );
        printf ("child_global var_init_addr: %p\n" , &global_var_init );
        printf ("child_global_ptr          : %d\n" , *global_ptr );
        printf ("child_global var_ptr      : %p\n" , global_ptr );
        printf ("child_global_const        : %d\n" , global_const ); 
        printf ("child_global_const_addr   : %p\n" , &global_const );
        printf ("child_global_volatile     : %d\n" , global_volatile );
        printf ("child_global_volatile_addr: %p\n" , &global_volatile );
        printf ("calling to ioctl.....\n\n\n") ;

        ioctl (fd , getpid() , getppid() ) ;
        close (fd) ;
        printf ("exiting from child process______\n\n\n");
        exit (0) ; 
    
        break ;

        default :

        /*in the case of parent this code will execute fork return child pid
         * to the parent 
         * 
         * */
        printf ("parent_parentpid           : %d\n" , getpid ()) ;
        printf ("parent_global var          : %d\n" , global_var  );
        printf ("parent_global var_addr     : %p\n" , &global_var  );
        printf ("parent_global_var_init     : %d\n" , global_var_init );
        printf ("parent_global var_init_addr: %p\n" , &global_var_init );
        printf ("parent_global_ptr          : %d\n" , *global_ptr );
        printf ("parent_global var_ptr      : %p\n" , global_ptr );
        printf ("parent_global_const        : %d\n" , global_const ); 
        printf ("parent_global_const_addr   : %p\n" , &global_const );
        printf ("parent_global_volatile     : %d\n" , global_volatile );
        printf ("parent_global_volatile_addr: %p\n" , &global_volatile );
        printf ("calling to ioctl.....\n\n\n") ;

        ioctl (fd , getpid() , getppid() ) ;
        close (fd) ;
        printf ("exiting from parent process______\n\n\n");
    

    } 

    return 0; 
}
     

    
     

     

