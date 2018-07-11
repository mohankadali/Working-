#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/types.h>

int main()
{

	int fd, i=0,j,p = 0;
	fd = open("/dev/spi_adc",O_RDWR);

	if(fd < 0)
		perror("Unable to open the Device");
	else
		printf("File opened successfully %d\n",fd);

		read(fd,&p,sizeof(p));
		printf("%d ------------fd = %d ----> \n",p, fd);
		close(fd);

	return 0;
}
