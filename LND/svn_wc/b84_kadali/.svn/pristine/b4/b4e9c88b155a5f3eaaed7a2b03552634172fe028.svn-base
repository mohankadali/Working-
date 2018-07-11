#include<stdio.h> 
#include<stdlib.h> 
int main() 
{
    int pid;
    pid = fork();
    if (pid == 0 )
    {
        printf ("I am child I done my job\n");
        exit(0);
    }
    else
    {
        printf ("child PID=%d\n",pid);
        printf ("go and check for zombie process\n");
      //  wait (1);
        getchar();
    }
    return 0;
}
