
#include "mypthread.h"
int process_create_process (void ) 
{
    int pid ; 

    pid = fork () ; 

    switch ( pid ) { 
        
        case -1 : 
            perror ("fork") ;
            break ;

        case 0 : 
            printf ("procees created child id =%d \n", getpid() );
            exit (0 ) ; 
            break ;

        default : 
            wait (NULL) ;
            printf ("process parent id     :  %d\n\n\n" , getpid());

    }
 
    return 0; 
}

