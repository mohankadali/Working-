#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 100

int fun_add()
{
    printf("hi i am in another process...\n");
    return 0;
}

int main()
{
    int fd1;
    int (*fun_ptr)();
    fun_ptr = fun_add;
    /* Creating the named pipe(FIFO) */
    mkfifo("myfile", 0666);

    char arr1[MAX];
    char arr2[MAX];
    //	while (1)
    //	{
    /* opening and writing into FIFO */
    fd1 = open("myfile",O_WRONLY);
    //		printf("enter msg to send:\n");
    //		fgets(arr1, MAX, stdin);
    //		write(fd1, arr1, strlen(arr1)+1);
    write(fd1, fun_ptr, strlen(fun_ptr)+1);
    close(fd1);
while (1);
    /* reading from FIFO */
    //		fd1 = open("myfile",O_RDONLY);
    //		read(fd1, arr2, MAX);
    //		read(fd1, arr1, MAX);
    //		printf("msg from dest: %s\n", arr1);
    //		printf("msg from dest: %s\n", arr2);
    //		close(fd1);
    //	}
    return 0;
}
