#include<stdio.h>
#include<pthread.h>

pthread_t tid[2];
unsigned int data = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* printevennos(void*);
void* printoddnos(void*);

void main(void)
{
        pthread_create(&tid[1],0,printoddnos,0);
        pthread_create(&tid[0],0,printevennos,0);

        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
}

void* printevennos(void *ptr)
{
        pthread_mutex_lock(&mutex);
        printf("_even\n");

        do
        {
                printf("even\n");
                if(data%2 == 0)
                {
                        printf("%d ",data);
                        data++;
                }
                else
                {
                }
                sleep(10);
                pthread_mutex_unlock(&mutex);
        } while (data <= 100);
}

void* printoddnos(void* ptr1)
{
        pthread_mutex_lock(&mutex);
        printf("_odd\n");

        do
        {
                printf("odd\n");
                if(data%2 != 0)
                {
                        printf("%d ",data);
                        data++;
                }
                else
                {
                        pthread_mutex_unlock(&mutex);
                }
                //     sleep(2);
        } while (data <= 100);
}


