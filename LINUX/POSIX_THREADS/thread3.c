#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
void* thread_fun2 (void*);
void* thread_fun1 (void*);
pthread_mutex_t  mutex1 = PTHREAD_MUTEX_INITIALIZER;
int c = 0;
int main ()
{
	pthread_t thread1, thread2 ;
	const char *msg1 = "thread1";
	const char *msg2 = "thread2";
	int ret1, ret2;    
	ret1 = pthread_create ( &thread1, NULL, thread_fun1, (void*)msg1 );
	if (ret1)
	{
		printf("pthread_create failed.....\n");
		exit(EXIT_FAILURE);
	}
	ret2 = pthread_create ( &thread2, NULL, thread_fun2, (void*)msg2 );
	if (ret2)
	{
		printf("pthread_create failed...\n");
		exit (EXIT_FAILURE); 
	}
	pthread_join (thread1,NULL);
	pthread_join (thread2,NULL);
	getchar();
	return 0;
}
void* thread_fun2 (void* ptr)
{
	int id = pthread_self();
	char *msg;
	msg = (char*)ptr;
	pthread_mutex_lock(&mutex1);
	while(1)
	{
		sleep(2);
		printf ("thread1 id =           %u\n",id);
		printf ("in thread fun1 msg :%s\n",msg);
	}
	pthread_mutex_unlock(&mutex1);
}
void* thread_fun1 ( void* ptr )
{

	int id = pthread_self();
	char *msg;
	msg = (char*)ptr;
	pthread_mutex_lock(&mutex1);
	while(1)
	{
		sleep(2);
		printf ("thread id =           %u\n",id);
		printf ("in thread fun msg :%s\n",msg);

	}
	pthread_mutex_unlock(&mutex1);
}
