/*main program to invoke the property of the thread  */
#include "mypthread.h"
int process_create_thread (void)
{
    pthread_t tid1 ;   /*thread id */
    int thread1_ret ;  /*thread return handle */
    int pid ; 
    pid = fork () ; 
    switch ( pid ) { 
        case -1 : 
            perror ( "fork" ) ; 
            exit ( EXIT_FAILURE ) ;
            break  ; 
        case 0 : 
            printf ("process created Child ID  : %d\n" ,  getpid () ) ; 
            printf ("child creating thread _  \n");
            thread1_ret = pthread_create (&tid1 , NULL , thread_id  , NULL ) ; 
            if ( 0 !=  thread1_ret  ) { 
                  perror ("pthread_create") ;
                 exit (EXIT_FAILURE ) ;
             }
            printf ("Thread created Group leader id :  %d\n" , getpid() );
            pthread_join ( tid1 , NULL ) ;
            exit (0)   ; 
            break ; 
        default : 
            wait ( NULL ) ;
            printf ("in parent process : %d\n\n\n"  ,getpid () );
    } 
    return 0; 
}
/* fuction defination to print id in thread */
void * thread_id ( void * tid  ) 
{ 
    printf ("created thread ID    : %d\n", getpid () ); 
    pthread_exit ( tid )  ; 
}
