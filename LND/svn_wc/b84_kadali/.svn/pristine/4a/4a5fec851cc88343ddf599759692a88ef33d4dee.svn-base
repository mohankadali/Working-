
/*main program to invoke the property of the thread  */

#include "mypthread.h"


int main(void)
{
 
    pthread_t tid1 ;   /*thread id */
    int thread1_ret ; 

    thread1_ret = pthread_create (&tid1 , NULL , thread_id  , NULL ) ; 

    if ( 0 !=  thread1_ret  ) { 
        perror ("pthread_create") ;
        exit (EXIT_FAILURE ) ;
    } 


    printf ("Group leader id :  %d\n" , getpid() );
    pthread_join ( tid1 , NULL ) ; 

    return 0; 
} 

/* fuction defination to print id in thread */

void * thread_id ( void * tid  ) 
{ 
    printf ("id of thread    : %d\n", getpid () ); 
    pthread_exit ( tid )  ; 
}
