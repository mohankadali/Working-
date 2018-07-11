#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
/* declarations */
pthread_t tid1;
pthread_t tid2;
pthread_t tid3;

struct st
{
	int a;
	int b;
};

int counter;
pthread_mutex_t lock;

void* doSomeThing(void *arg)
{  
  //  pthread_mutex_lock(&lock);

	int max = *(int *)arg;
	
	printf("max:%d\n", max);

    pthread_mutex_lock(&lock);
 
    pthread_mutex_trylock(&lock);

    counter += 1;

	printf("Thread prints data1:\n");


    pthread_mutex_unlock(&lock);

    return NULL;
}

void add (void *ptr)
{
		sleep(10);
		printf("in thread2\n");
	waitpid(tid1);
    pthread_mutex_lock(&lock);
 
    pthread_mutex_trylock(&lock);
	struct st *pt =  (struct st*) ptr;
	pt->a = 10;
	pt -> b = 20;
	int res = (pt->a) + (pt->b);
	printf("%d\n",res);
	pthread_mutex_unlock(&lock);
}
void sub (void *ptr)
{
	sleep(15);

		printf("in thread 3\n");
	waitpid (tid2);
    pthread_mutex_lock(&lock);
 
    pthread_mutex_trylock(&lock);
	struct st *pt =  (struct st*) ptr;
	pt->a = 30;
	pt -> b = 40;
	int res = (pt->a) - (pt->b);
	printf("%d\n",res);
	pthread_mutex_unlock(&lock);
}


int main(void)
{
	struct st s1;
	struct st *ptr = malloc(sizeof(struct st)) ;
		
    int i = 0;
    int err;
   /* mutex dynamic intialization */
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
   
   
        err = pthread_create(&(tid1), NULL, &doSomeThing, ptr );
        if (err != 0)
            perror("pthread_create");
        
        err = pthread_create(&tid2, NULL, &add, ptr );
        if (err != 0)
            perror("pthread_create");
   
        err = pthread_create(&(tid3), NULL, &sub, ptr );
        if (err != 0)
            perror("pthread_create");

//	waitpid (tid1);
  pthread_join(tid1, NULL);

    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
