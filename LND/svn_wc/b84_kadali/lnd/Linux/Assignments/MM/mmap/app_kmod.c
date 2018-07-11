
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    int fd ;
    int pid;
    pid = getpid();
    fd = open ("/dev/mychar", O_RDWR) ;
    if ( fd < 0 ) {
        perror ("unable to open the device") ;
    } else {
        printf ("File opened succesfully %d\n", fd) ;
    }
    printf("Process id From App is %d \n",pid);
    ioctl(fd,1,pid);
    close (fd) ;
    return 0 ;
}
