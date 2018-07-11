
/* programm to understand the fork behavior on global data */


/*
 * conclusion : 
 *
 * in the fork system  call : 
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
int status ;  



int global_var_experiment (void)
{

    global_ptr = malloc (sizeof (int)*15 ) ;
    *global_ptr  = 60 ;

    if(!(pid = fork())) 
    {

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
        printf ("*******exiting from child process*******\n\n\n");
        exit (0) ; 

    }
    else
    {
        /*in the case of parent this code will execute fork return child pid
         * to the parent 
        */
        wait (&status) ; 
        
        global_var   = 123  ;                      /*global data under experiment */
        global_var_init = 100 ;             /*init data under experiment  */
        *global_ptr = 200 ;                     /*global pointer in data */
        // global_const = 25 ;          /*global data in ro section */
        global_volatile = 7 ;    /*global volatile is in data */
        
        printf ("parent_pid                 : %d\n" , getpid ()) ;
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
        printf ("********exiting from parent process********\n\n\n");
    } 

    return 0; 
}


    
     

     

