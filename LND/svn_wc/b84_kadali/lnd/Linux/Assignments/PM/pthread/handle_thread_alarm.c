
#include "mypthread.h"

void *  m_handle_thread_alarm ( void * line   ) 
{

    int seconds  ;
    char msg[MSG_SIZE] ; 


    if (sscanf (line , "%d %64[^\n]" , &seconds , msg) < 2 ) {
        printf ("Bad command \n");
    }
    
    sleep ( seconds ) ;
    printf ("%d %s\n" ,  seconds , msg );
    pthread_mutex_unlock ( &mlock ) ; 

    pthread_exit ( NULL ); 

}

