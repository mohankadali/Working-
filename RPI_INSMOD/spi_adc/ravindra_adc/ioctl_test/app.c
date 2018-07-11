#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

//#include "query_ioctl.h"

int main(int argc, char *argv[])
{
				printf("--------------\n");
				char *file_name = "/dev/spi_adc";
				int fd,q;

				fd = open(file_name, O_RDWR);

				if (fd < 0)
				{
								perror("query_apps open");
								printf(" File not open...\n");
								return 2;
				} else {
								printf("+++++++++++++\n");
				}

				//if (ioctl(fd, QUERY_SET_VARIABLES, &q) == -1)
				if (ioctl(fd, 1, &q) == -1)
				{
								perror("query_apps ioctl set");
				} else {
								printf("ioctl fail..\n");
				}

				close (fd);

				return 0;
}
