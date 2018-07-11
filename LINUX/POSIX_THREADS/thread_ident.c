#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
/* to catch thread ids in thread id function*/
pthread_t tid[2000];

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    /* to compare thread ids*/

    if(pthread_equal(id,tid[0]))
    {
        printf("\n First thread processing\n");
    }
    else
    {
        printf("\n Second thread processing\n");
        for(i=0; i< sizeof (int);i++);

        return NULL;
    }
}

int main(void)
{
    int i = 0;
    int err;
    pthread_attr_t tattr;
    int ret;
    /* set the thread detach state */
    ret = pthread_attr_setdetachstate(&tattr,PTHREAD_CREATE_DETACHED);

    if ( ret != 0) {
        printf("detach failed\n");
    }

        





    while(i < 2000)
    {
        err = pthread_create(&(tid[i]), &tattr, &doSomeThing, NULL);
        if (err != 0)
            perror("pthread_create");
        else
            printf("\n Thread created successfully\n");

        i++;
    }
    /*
    if( pthread_detach(tid[0]))
        perror("pthread_detach");
    else
        printf("pthread_detach successful\n",);*/

    sleep(5);
    return 0;
}

