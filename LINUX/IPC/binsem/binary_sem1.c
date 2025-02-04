#include <semaphore.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* function1(void* val);
void* function2(void* val);

// shared values
volatile int X;
volatile int Y;

// declare semaphores
sem_t s1;
sem_t s2;

main()
{
	void* status;

	pthread_t thread1;
	pthread_t thread2;
	srand(time(NULL));

	// initialize semaphores to zero
	sem_init(&s1, 0, 0);
	sem_init(&s2, 0, 0);

	pthread_create(&thread1, NULL, function1, NULL);
	pthread_create(&thread2, NULL, function2, NULL);

	pthread_join(thread1, &status);
	pthread_join(thread2, &status);

	sem_destroy(&s1);
	sem_destroy(&s2);

}

void* function1(void* val)
{
	while(1)
	{
//		sem_wait(&s2); // wait
		X = rand()%1000; // write 
		printf("After thread ID A writes to X, X = %d\n", X);
		sem_post(&s1); // signal
		sem_wait(&s2); // wait
		printf("After thread ID A reads from Y, Y = %d\n", Y); // read
//		sem_post(&s1); // signal
		sleep(3);
	}   
}

void* function2(void* val)
{
	while(1)
	{
		sem_wait(&s1); // wait
		printf("After thread ID B reads from X, X = %d\n", X); // read
		Y = rand()%1000; // write
		printf("After thread ID B write to Y, Y = %d\n", Y);
		sem_post(&s2); // signal
		sleep(3);
	}
}
