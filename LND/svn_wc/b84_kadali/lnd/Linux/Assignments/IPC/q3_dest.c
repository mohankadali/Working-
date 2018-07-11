#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 100

int main()
{
    int fd;

    /* Creating the named pipe(FIFO) */
    mkfifo("myfile", 0666);
    int *fun;
    //char sbuf [10];
    //	char arr1[MAX];
    //  char arr2[MAX];

    //	while (1)
    //	{
    /* reading from FIFO */
    fd = open("myfile", O_RDONLY);
    read(fd, fun, MAX);
    //		read(fd, sbuf, MAX);
    //		printf("msg from src: %s\n", arr1);
    //printf("%s\n", sbuf);
//    fun();
    close(fd);
    /* opening and writinginto FIFO */
    //		fd = open("myfile", O_WRONLY);
    //		printf("enter msg to send\n");
    //		fgets(arr1, MAX, stdin);
    //		write(fd, arr1, strlen(arr2)+1);
    //		fgets(arr2, MAX, stdin);

    //        write(fd, arr2, strlen(arr2)+1);
    //		close(fd);

    //	}
    return 0;
}
