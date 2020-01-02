#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
        int fd;
        char * myfifo = "/tmp/mohan";

        /* create the FIFO (named pipe) */
        mkfifo(myfifo, 0000);

        /* write "Hi" to the FIFO */
        printf ("before write..\n") ;   
        // open is blocking the prog execution.
        fd = open(myfifo, O_WRONLY);
        write(fd, "Hi", sizeof("Hi"));
        close(fd);

        /* remove the FIFO */
        unlink(myfifo);

        return 0;
}
