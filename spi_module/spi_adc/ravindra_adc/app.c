#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

//#include "query_ioctl.h"

int main(int argc, char *argv[])
{
				printf("--------------\n");
				char *file_name = "/dev/spi_adc";
				int *address = NULL;
				int fd,q;

				fd = open(file_name, O_RDWR);

				if (fd < 0)
				{
								perror("query_apps open");
								printf(" File not open...\n");
								return 0;
				} else {
								printf("+++++++++++++\n");
				}
/*
				//if (ioctl(fd, QUERY_SET_VARIABLES, &q) == -1)
				if (ioctl(fd, 1, &q) !=0)
				{
								printf("ioctl fail..\n");
				} else {
								printf("================== %d=== \n",q);
								perror("query_apps ioctl set");

				}
 */
				address = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
				if (address == MAP_FAILED)
				{
								perror("mmap operation failed");
								return -1;
				} else {
								perror("mmap operation sucsess");
								printf("--------------------%d ..\n",*address);
				}
				close (fd);

				return 0;
}
