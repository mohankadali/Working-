#include<stdio.h>
int main(void)
{

    printf("pid : %d\n",getpid());
    int pid;


    pid = fork();
    if (pid == 0)
    {
        printf("child\n");
    }
    else {
        printf("parent\n");
    }
    getchar();
    return 1;
}
