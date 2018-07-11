
#include "fork.h"
int main(void)
{
    int fd ; 

    fd = open ("/dev/my_ps", O_RDWR ) ;

    if ( fd < 0 )  { 
      perror("open");
      exit (0) ;
    }  else { 
        printf ("File open successful\n");
    }

    printf ("process id = %d\n" , getpid() );
    ioctl (fd , getpid() , getppid()) ; 

    close (fd) ; 

    return 0; 
} 
