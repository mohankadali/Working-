#include<stdio.h> 
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void *thread1(void *ptr); 
void *thread2(void *ptr); 
void *thread3(void *ptr); 
int a =10;
int main(void)
{
    int pid;
    pthread_t th_id1;
    pthread_t th_id2;
    pthread_t th_id3;
    pid = pthread_create(&th_id1,NULL,thread1,NULL);
    if (pid == -1) {
        printf ("error in creation ...\n");
        return 0;
    }
    ptread_join(th_id1,NULL);



    pid = pthread_create(&th_id1,NULL,thread2,NULL);
    if (pid == -1) {
        printf ("error in creation ...\n");
        return 0;
    }
    ptread_join(th_id1,NULL);


    pid = pthread_create(&th_id1,NULL,thread3,NULL);
    if (pid == -1) {
        printf ("error in creation ...\n");
        return 0;
    }
    ptread_join(th_id1,NULL);



    printf ("a value is %d\n",a);
    return 0;
}
void *thread1(void *ptr) 
{
    a =20;
    printf ("in thread1 a value is %d\n",a);
    pthread_exit(NULL);
}

void *thread2(void *ptr) 
{
    a =30;
    printf ("in thread1 a value is %d\n",a);
    pthread_exit(NULL);
}

void *thread3(void *ptr) 
{
    a =40;
    printf ("in thread1 a value is %d\n",a);
    pthread_exit(NULL);
}
