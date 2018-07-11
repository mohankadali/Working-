#include <stdio.h>
#include<stdlib.h> 
int main()
{
    int pid = vfork ();
    if (pid == 0)
    {
        printf("i am child %d,   my parent is %d\n",getpid(),getppid());
//        exit(0);
    }
    else
    {
        printf("i am parent %d,   my child is %d\n",getpid(),pid);
    }
    return 0;
}
