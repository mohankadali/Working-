#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
int main(void)
{
	int fd,pid;
	//myioctl (1, pid);
	fd = open("/dev/myChar", O_RDWR);
	printf("file opened %d\n", fd);    
	pid = getpid();
	if(fd < 0)
		perror("unable to open device");
	else
		printf("File opened succesfully=%d\n" , fd);
	ioctl(fd, pid, NULL);
	
	close (fd);
	return 0;
}
