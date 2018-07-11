
/* programm to understand the fork behavior on local data */

#include "mypthread.h"

void* local_var_experiment (void* tid1)
{
    int local_var  ;                      /*local variable under experimant */
    int local_var_init = 36 ;             /* init var under fork experiment */
    int *local_ptr  ;                     /*heap data in experimant   */
    int const local_const = 98 ;          /*stack data in expermant  */
    int volatile local_volatile = 34 ;    /*stack data in expeimant  */

    local_ptr = malloc (sizeof (int)*15 ) ;
    *local_ptr  = 362 ;

        printf ("thread_local_id    : %d\n" , getpid ()) ;
        printf ("local var          : %d\n" , local_var  );
        printf ("local var_addr     : %p\n" , &local_var  );
        printf ("local_var_init     : %d\n" , local_var_init );
        printf ("local var_init_addr: %p\n" , &local_var_init );
        printf ("local_ptr_heap     : %d\n" , *local_ptr );
        printf ("local var_ptr_heap : %p\n" , local_ptr );
        printf ("local_const        : %d\n" , local_const ); 
        printf ("local_const_addr   : %p\n" , &local_const );
        printf ("local_volatile     : %d\n" , local_volatile );
        printf ("local_volatile_addr: %p\n" , &local_volatile );
        printf ("exiting from child process______\n\n\n");
 
        pthread_exit (&tid1) ; 
    
} 


    
     

     

