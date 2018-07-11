


#include "mypthread.h"

/*program for synchronous alarm  vy using thread   */

pthread_t  tid ; 
pthread_mutex_t mlock = PTHREAD_MUTEX_INITIALIZER ; 
int main(void)
{
    char line [LINE_BUF] ; 
    int thread_ret ;  

   printf ("Input Formatt :   <seconds>  <space> <Msg>\n");

   while ( 1 ) {
     
   printf ("Alarm :> "); 

   if ( NULL == fgets ( line , sizeof (line) , stdin ) )  {
   perror ( "fgets"  ) ; 
   exit ( EXIT_FAILURE ) ; 
   }

   /*if input is less then one char skip that iteration  */

   if  (strlen (line )  <= 1 ) 
       continue ; 

   /*create the thread before parsing the masges   */
       
   thread_ret = pthread_create ( &tid , NULL , m_handle_thread_alarm , line ) ; 

       if ( thread_ret != 0 ) { 
           perror ("pthread_create FAIL \n");
           exit ( EXIT_FAILURE ) ; 
          }

   }

   return 0; 
}




    

    
