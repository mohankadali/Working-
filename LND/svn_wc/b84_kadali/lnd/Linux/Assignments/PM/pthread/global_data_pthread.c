
/* programm to understand the fork behavior on global data */

#include "mypthread.h"

    int global_var  ;                      /*global data under experiment */
    int global_var_init = 30 ;             /*init data under experiment  */
    int *global_ptr  ;                     /*global pointer in data */
    int const global_const = 25 ;          /*global data in ro section */
    int volatile global_volatile = 70 ;    /*global volatile is in data */
    int pid  ;                 
    int status ;  

void*  global_var_experiment (void* tid2)
{

    global_ptr = malloc (sizeof (int)*15 ) ;
    *global_ptr  = 90 ;

        printf ("thread_global_id    : %d\n" , getpid ()) ;
        printf ("global var          : %d\n" , global_var  );
        printf ("global var_addr     : %p\n" , &global_var  );
        printf ("global_var_init     : %d\n" , global_var_init );
        printf ("global var_init_addr: %p\n" , &global_var_init );
        printf ("global_ptr          : %d\n" , *global_ptr );
        printf ("global var_ptr      : %p\n" , global_ptr );
        printf ("global_const        : %d\n" , global_const ); 
        printf ("global_const_addr   : %p\n" , &global_const );
        printf ("global_volatile     : %d\n" , global_volatile );
        printf ("global_volatile_addr: %p\n" , &global_volatile );
        printf ("exiting from thread ______\n\n\n");

        /*modifing the global variable by thread  */
        global_var = 67 ; 
        global_var_init = 98 ; 
        global_volatile = 55 ; 


        pthread_exit (&tid2 ) ; 
    
}
