#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
/* declarations */
pthread_t tid[2];
int counter;
pthread_mutex_t lock;
 pthread_mutex_t mutex;

void* doSomeThing(void *arg)
{  /* mutex lock creation */

    pthread_mutex_lock(&lock);

    unsigned long i = 0;

//    pthread_mutex_lock(&lock);

    pthread_mutex_trylock(&lock);/* try lock */

    counter += 1;

    printf("\n Job %d started\n", counter);

    for( i = 0; i < sizeof (int); i++ );

    printf("\n Job %d finished\n", counter);


    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    /* mutex intialization with attributes */
    pthread_mutexattr_t attr;

    pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_ERRORCHECK);

    err = pthread_mutex_init (&mutex, &attr);

  if ( err != 0 ) {

      printf("mutex failled\n");
  }


   /* mutex dynamic intialization */
    /*if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }*/

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, &attr);
        if (err != 0)
            perror("pthread_create");
        i++;
    }

    pthread_join(tid[0], NULL);

    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
