#include <stdio.h>
#include<semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdlib.h>

sem_t *addr;
int main(void)
{
    int fd,i;
    int *p = NULL;
    fd = shm_open("/sh2", O_CREAT | O_RDWR, 0666);

    /* shm return -1 on failure*/

    if (fd < 0) {
        perror("shm_open failed");
        exit (0);
    }

    ftruncate (fd, 8192);

    /* On success mmap return poitner to maped area*/


//    p = mmap(NULL,80, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 4096);
     // p = mmap(0x0804b111,10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
      p = mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%p  \n", p);
    if ( p < 0) {
        perror("mmap failed");
        exit (0);
    } 

    addr = sem_open("/sem3", O_CREAT| O_RDWR , 0666, 1);
    sem_init(addr, 1, 1);
    printf("%p\n", addr);
    printf("enter 10 element..... \n");

    sem_wait(addr);

    for (i = 0; i < 10; i++) {
        scanf("    %d" , (p+i));
    }

    sem_post (addr); 

    	sleep (2);
  //  	for (i=0; i<5; i++)
 //   	printf("%d", p[i]);
    sem_unlink("/sem3");
    return 0;
}


