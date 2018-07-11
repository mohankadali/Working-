#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <malloc.h>
#include <syscall.h>

#define UNSET 0

void* thread_fun2 (void* fun2);

//thread function
void *thread_fun ( void *heap )
{
    pthread_t id;
    int stat;

    id = pthread_self();
    //printf("self %p\n",id);



	printf ("\n***In Thread***\n");
    printf ("Thread Group Leader ID : %d \n", getpid() );

	/* thread id */
	pid_t tid = gettid();

	printf ("Thread ID : %d \n", (int)tid );

    printf("Thread parent id %d\n",getpid());
    printf("Thread ppid = %d\n",getppid());

    stat =  pthread_create ( &id , NULL, &thread_fun2, NULL );

    if ( 0 == stat)
    {
        printf("thread creation succees\n");
    }else{
        printf("thread creation failled\n");
    }

    pthread_join (id,NULL);

    getchar();
	pthread_exit (NULL);
    

}

void *thread_fun2 ( void *fun2 )
{
    int stat;



	printf ("\n***In Thread2***\n");
    printf ("Thread Group Leader ID : %d \n", getpid() );
	
    /* Thread id*/
	pid_t thid = gettid();

	printf ("Thread ID : %d \n", thid );
}
/* our own wrapper  function */
pid_t gettid ()
{
	pid_t tid = syscall ( SYS_gettid );
}

int main ( void )
{
	pthread_t t_id;

	printf("\n***In Main ***\n");	

    printf("pid = %d\n",getpid());
    printf("ppid = %d\n",getppid());
	
	pid_t tid = gettid();

    int status;



	/* printf ("Thread ID : %d \n", tid );*/
	printf ("Thread group leader i.e Main Thread ID : %d \n", getpid() );
	/*to create a thread */
	status = pthread_create ( &t_id , NULL, &thread_fun, NULL );
	pthread_join ( t_id ,NULL);
/* main thread id printing */
    printf(" main thread id = %d\n",(int)tid);
	if ( UNSET == status ) {
		printf("\nThe pthread successfull.. %d\n\n",status);
	}
	else {
		printf("Failed..\n");	
	}
    getchar();
return 0;
}

// compile code with -lpthread library
