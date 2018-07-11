#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * detachable_thread()
{
	sleep(10);
	printf("This is a detachable threads going to sleep for 10 seconds\n ");
}

int main()
{
	int ret;
	pthread_t thread_id;
	pthread_attr_t attr_id;
	ret = pthread_attr_init(&attr_id);
	if(ret != 0)
	{
		perror("error attribute initialize\n");
		return -1;
	}
	ret = pthread_attr_setdetachstate(&attr_id, PTHREAD_CREATE_DETACHED);
	if(ret != 0)
	{
		perror("set detach");
		return -1;
	}
	// using that detachable thread attribute as second argument
	ret = pthread_create(&thread_id, &attr_id, detachable_thread ,NULL);
	if(ret != 0)
	{
		perror("error in thread creation");
		return -1;
	}
	pthread_attr_destroy(&attr_id);	
	pthread_exit(NULL);
}
