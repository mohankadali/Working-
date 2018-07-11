#include <stdio.h>
#include<unistd.h>
int main()
{
    int pid_t = fork ();        // creating child process.
    if (pid_t)             // condition checking for parent process
    {
        printf ("i am parent %d \n",getpid());
        if (pid_t = fork())             // condition checking for parent process
        {
            printf ("i am parent %d  \n",getpid());
            if (pid_t = fork())             // condition checking for parent process
            {
                printf ("i am parent %d  \n",getpid());
                getchar();
            }
            else                        // child3 process
            {
                printf ("i am child3 %d,   my parent is %d\n",getpid(),getppid());
            }
        }
        else                        // child2 process
        {
            printf ("i am child2 %d,   my parent is %d\n",getpid(),getppid());
        }
    }
    else                        // child1 process
    {
        printf ("i am child1 %d,   my parent is %d\n",getpid(),getppid());
    }
    return 0;
}
