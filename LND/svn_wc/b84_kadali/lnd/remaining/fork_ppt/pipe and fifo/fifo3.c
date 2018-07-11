#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	char str[20];
	int fd2;
//	mkfifo("f", 0666);
 //   perror("mkfifo");
	
	fd2 = open("f", O_RDONLY);
	
	read(fd2, str, sizeof(str));
	printf("%s\n", str);

	close(fd2);
	printf("client : my work completed\n");	
	return 0;
}

