

#include "mypthread.h"

void* file_write (void * tid ) 
{ 
    printf ("Thread created for file writing \n");
    printf ("PID    :  %d\n", getpid () );
    int fd ; 

    fd = open ("just.txt", O_RDWR); 
    if (fd < 0 ) { 
        perror ("open"); 
        exit (EXIT_FAILURE)  ; 

    } 

    write ( fd , "software limited" , strlen ("software limited") ) ; 
    close ( fd ) ; 

    pthread_exit ( &tid ) ; 
}
   
