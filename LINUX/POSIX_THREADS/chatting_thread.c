#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 
char n[1024];
//sem_t len;
int len;
void *read1()
{
	printf("The len: %d\n", len);
	while(1){
		printf("Enter a string\n");
		scanf("%s",n);
		sem_post(&len);
		printf("sem_post %d\n", len);
		sleep(1);
	}
}
void *write1()
{
	while(1){
		printf("write\n");
		sem_wait(&len);
		printf("sem_wait %d\n", len);
		printf("The string entered is :");
		printf(" %s\n",n);
	}

}
int main()
{
	int status;
	pthread_t tr, tw;

	pthread_create(&tw,NULL,write1,NULL);
	pthread_create(&tr,NULL,read1,NULL);

	pthread_join(tr,NULL);
	pthread_join(tw,NULL);
	return 0;
}
