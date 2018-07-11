
/*main program to invoke the property of the thread  */

#include "mypthread.h"


int thread_create_process (void)
{
 
    pthread_t tid1 ;   /*thread id */
    int thread1_ret ;  /*thread return handle */

    printf ("creating a Thread ....\n\n");    

    thread1_ret = pthread_create (&tid1 , NULL , thread_id1  , NULL ) ; 

    if ( 0 !=  thread1_ret  )  { 
        perror ("pthread_create") ;
        exit (EXIT_FAILURE ) ;
     }

    printf ("thread crated Group leader id :  %d\n" , getpid() );

    pthread_join ( tid1 , NULL ) ; 
                      
    return 0;
}

/*thread creating process  */

void * thread_id1 ( void * tid  ) 
{ 
    int pid ;

    printf ("created thread id      : %d\n", getpid () ); 
    printf ("Thread creation a new process : \n");
    pid = fork( ) ;                              

    switch ( pid ) { 

        case -1 : 
            perror ( "fork" ) ; 
            exit ( EXIT_FAILURE ) ;
            break  ; 

        case 0 : 

            printf ("process created by thread Child ID  : %d\n" , getpid () ) ; 

            break ; 

        default : 

            wait ( NULL ) ;
            printf ("process created by thread Parent ID : %d\n"  ,getpid () );
    } 

    pthread_exit ( tid )  ; 


}
