#include<stdio.h>
#include<semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdlib.h>
sem_t *addr;
int main(void)
{
	int fd, i;
	int *p = NULL;
 	fd = shm_open("/sh2", O_RDWR , 0666);
	
    /*shm return -1 on failure 
     * success fd
     */
    
    if(fd < 0) {
	perror("shm failed");
    exit (0);
    }

    /* ftruncatre return 0 on succes*/	
    
     ftruncate(fd, 80);
    
	
    p = mmap (NULL, 80, PROT_READ|PROT_WRITE ,MAP_SHARED, fd, 0);
//    p = mmap (0x08048320 , 80, PROT_READ|PROT_WRITE ,MAP_SHARED, fd, 160);
	
	if(p < 0) {
	perror("shm failed");
	exit (0);
    }
	
	addr = sem_open ("/sem3", O_CREAT);
	sem_init(addr,1,1);
	printf ("waiting..... sem1");

	sem_wait(addr);

	for (i = 0; i<5; i++){
	printf ("%d\t", *(p+i));
	}
	sem_post(addr);

	for(i=0 ; i<5; i++){
	*(p+i) =0;
         }
	sem_unlink("/sem3");
return 0;
}

