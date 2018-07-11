

/*main program to invoke the property of the thread  */


#include "mypthread.h"


int main(void)
{

    printf ("In main PID  : %d\n "  , getpid() ) ;

    printf ("process create process : \n\n\n");
    process_create_process ( ) ;
    sleep (1) ;  
    
    printf ("process create thread  : \n\n\n");
    process_create_thread ( ) ;
    sleep (1) ;  
    
    printf ("thread  create process : \n\n\n");
    thread_create_process ( ) ; 
    sleep (1) ;  
    
    printf ("thread  create thread  : \n\n\n");
    thread_create_thread ( ) ;
    sleep (1) ;  

   return 0; 

}  

