#include<stdio.h> 
#include<stdlib.h>
#include<signal.h>

void sig_handler (int n) ;          
int main()
{
    int pid = fork();

    if (pid == 0)
    {
        /*in  child process*/

        printf ("child %d\n",getpid());
        printf ("I am child, Go and check who is my parent..\n");
        sleep (10 );
        getchar ();
//        exit(0);
    }
    else       
    {   
        /*  in  parent process*/ 

        /*creating siganl handler for SIGCHLD(17) signal*/

        signal ( SIGCHLD, sig_handler );
        wait(1);
        printf("parent %d\n",getpid());
        printf("I am parent, I done my job\n");
        while (1);
    }
    return 0;
}

/* sig_handler function  */

void sig_handler (int n)           
{
    printf ("\nin sig_handler\n");
}
