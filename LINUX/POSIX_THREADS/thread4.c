#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
void* inc (int);
void* dec (int);
int count  = 0;
pthread_mutex_t  mutex1 = PTHREAD_MUTEX_INITIALIZER;
int c = 9;
int main ()
{
	pthread_t thread1, thread2 ;
	int i = 1;
	int d = -1;
	int ret1, ret2;    
	ret1 = pthread_create ( &thread1, NULL, inc, i );
	if (ret1)
	{
		printf("pthread_create failed.....\n");
		exit(EXIT_FAILURE);
	}
	ret2 = pthread_create ( &thread2, NULL, dec, d );
	if (ret2)
	{
		printf("pthread_create failed...\n");
		exit (EXIT_FAILURE); 
	}
	pthread_join (thread1,NULL);
	pthread_join (thread2,NULL);
//	printf("sum = %d\n",c);  
	getchar();
	return 0;
}

void* inc (int ptr)
{
	pthread_mutex_lock(&mutex1);
	printf("in inc\n");
	int x = 0;
	while(c <= 10)
	{
		c = c + ptr;
//		x++;
		    printf("%d \n",c);
	}
	pthread_mutex_unlock(&mutex1);
}
void* dec ( int ptr )
{

	pthread_mutex_lock(&mutex1);
	printf("in dec\n");
	int x = 0;
	while(c <= 10)
	{
		c = c - ptr;
//		x++; 
		  printf("%d \n",c);
	}
	pthread_mutex_unlock(&mutex1);
}
