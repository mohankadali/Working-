#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	char str1[20];
	char str2[20];
	char str3[20];
	int fd;
	int fd1;
	int fd2;
//	mkfifo("f", 0666);
//	perror("mkfifo");

//	mkfifo("f1", 0666);
//	perror("mkfifo");
	
	fd = open("f", O_WRONLY);
	printf("enter data for client1 \n");
	scanf("%[^\n]s", str1);
	write(fd, str1, sizeof(str1));

	fd1 = open("f", O_WRONLY);
	printf("enter data for client2\n");
	scanf(" %[^\n]s", str2);
	write(fd1, str2, sizeof(str2));
	close(fd);
	close(fd1);
	fd1 = open("f", O_WRONLY);
	printf("enter data for client3\n");
	scanf(" %[^\n]s", str3);
	write(fd2, str3, sizeof(str3));
	close(fd2);
	printf("server : my work completed\n");	
	return 0;
}

