#include <stdio.h>
#include<stdlib.h> 
int main()
{
    int pid = vfork ();
    if (pid == 0)
    {
        printf("i am child %d\n",getpid());
        exit(0);
    }
    else
    {
        printf("i am parent %d\n",getpid());
    }
    return 0;
}
