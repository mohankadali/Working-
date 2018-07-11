#include <stdio.h>
#include<unistd.h>
int x=10;
int main()
{
    int y=20;
    int pid_t = vfork ();        // creating child process.
    int *p = malloc(10);
    *p = 30;
    if (pid_t < 0)
    {
        printf("fork failed...\n");
        return 0;
    }
    else if (pid_t)             // condition checking for parent process
    {
        *p = 40; 
        printf ("i am parent %d,   my child is %d\n",getpid(),pid_t);
        printf("in parent %p  %p  %p\n",&x,&y,p);
        wait(0);
    }
    else                        // child process
    {
        printf ("i am child %d,   my parent is %d\n",getpid(),getppid());

        printf("in child %p  %p  %p\n",&x,&y,p);
    }
    printf("modified =  %d    %p\n",*p,p);

        exit(0);
    return 0;
}
