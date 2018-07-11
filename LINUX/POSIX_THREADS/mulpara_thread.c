#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct record
{
    int count;
    char array[15];
};

void * example_thread(void * r)
{
    struct record *r1 = (struct record *)r;
    printf("argument are %d and string is %s\n",r1->count,r1->array);

}

int main()
{
    int ret;
    int count  =12;
    struct record r1 = {4, "hello"};
    pthread_t thread_id;
    ret = pthread_create(&thread_id, NULL, example_thread ,(void *)&r1);
    if(ret != 0)
    {
        perror("error in thread creation");
    }
    pthread_join(thread_id, NULL);
}
