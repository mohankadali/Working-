
/*main program to invoke the property of the thread  */

#include "mypthread.h"

pthread_t tid1 ;                         /*thread id first   */ 
pthread_t tid2 ;                         /*thread id  two   */
pthread_t tid3 ;                         /*thread id  two   */
extern int global_var  ; 
extern int global_var_init ;             /*init data under experiment*/
extern int *global_ptr  ;                /*global pointer in data */
extern int const global_const  ;         /*global data in ro section*/
extern int volatile global_volatile ;    /*global volatile is in data*/


int main(void)
{
 
    int thread1_ret ;                     /*thread_create return value  */
    int thread2_ret ;
    int thread3_ret ;
    int local_var  ;                      /*local variable under experimant*/  
    int local_var_init = 30 ;             /* init var under fork experiment*/  
    int *local_ptr  ;                     /*heap data in experimant */
    int const local_const = 25 ;          /*stack data in expermant */
    int volatile local_volatile = 70 ;    /*stack data in expeimant */
    int fd ; 

   
    /*locla data under experiment  */

     local_ptr = malloc (sizeof (int)*15 ) ;
     *local_ptr  = 60 ; 

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

    printf ("Thread is creating  for local var experiment \n\n\n"); 
    sleep (1) ; 
    thread1_ret = pthread_create (&tid1 , NULL , local_var_experiment , NULL ) ; 

    if ( 0 !=  thread1_ret  ) { 
        perror ("pthread_create") ;
        exit (EXIT_FAILURE ) ;
    }

    
    printf ("Group leader id %d\n" , getpid() );
    pthread_join ( tid1 , NULL ) ;                         /*wait for thread 1 */

    sleep (5) ;

    /*global data under experiment  */
    global_ptr = malloc (sizeof (int)*15 ) ;
    *global_ptr  = 60 ;

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

    printf ("Thread is creating  for global var experiment \n\n\n"); 
    thread2_ret = pthread_create (&tid1 , NULL , global_var_experiment , NULL ) ; 


    if ( 0 !=  thread2_ret  ) { 
        perror ("pthread_create") ;
        exit (EXIT_FAILURE ) ;
    } 

    printf ("Group leader id %d\n" , getpid() );
    pthread_join ( tid2 , NULL ) ; 

    sleep (1) ;

    /*after thread called and modification in data done in thread  */
    printf ("afte calling  thread global heap data change : \n"); 
    printf ("global var          : %d\n" , global_var  );
    printf ("global_ptr          : %d\n" , *global_ptr );
    printf ("global_var_init     : %d\n" , global_var_init );
    printf ("global_const        : %d\n" , global_const );
    printf ("global_volatile     : %d\n" , global_volatile );

    /*file operations by thread  */
    printf ("operation on file..............\n\n\n");
    fd = open ( "just.txt" , O_RDWR ) ; 

    if ( fd < 0 ) { 
        perror ("open") ; 
        exit (EXIT_FAILURE) ; 
    } 

    printf ("writing from TGL \n\n");
    write (fd ,"Global Edge", strlen ("Global Edge "));

    close (fd );

    printf ("Creating thread for writing  \n");
    thread3_ret = pthread_create (&tid3 , NULL , file_write , NULL ) ; 

    if ( 0 !=  thread3_ret  ) { 
        perror ("pthread_create") ;
        exit (EXIT_FAILURE ) ;
    }

    printf ("Thread created TGL id   : %d\n" , getpid () );
    pthread_join ( tid3 , NULL ) ; 

    return 0; 
} 



