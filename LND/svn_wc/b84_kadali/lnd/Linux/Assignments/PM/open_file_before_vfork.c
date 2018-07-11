
#include "fork.h"                    /*header file for fork operation */

/* 
 * conclusion  : 
 * the string written in the file are : 
 * double referance error  
 *
 * */
int open_my_file_txt ( void ) 
{ 
    int fd ;                        /*file descriptor to open file  */      
    int pid ;  
    fd = open ("just.txt", O_RDWR ) ; /*open the file to perform write operation */
    
    pid = vfork () ; 
    if ( -1 == pid ) { 
        perror ("fork") ;
    }

    if (0 == pid  )  { 
        printf ("child id  = %d\n" , getpid() );
        write ( fd , "Software Limited", strlen("Software limited") ) ; 
        /*write into the file from child process  */
        close (fd )  ;
    } else { 
        printf ("parent  id  = %d\n" , getpid() );
        write ( fd , "Global Edge", strlen("Global Edge") ) ;
        /*write in the file from parent  */
        close (fd )  ;
    }

    return 0;  
} 



    
