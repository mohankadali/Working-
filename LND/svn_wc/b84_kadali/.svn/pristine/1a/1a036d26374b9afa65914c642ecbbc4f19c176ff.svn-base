#include<stdio.h> 
#include<stdlib.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf ("child %d\n",getpid());
        printf ("I am child, Go and check who is my parent..");
        getchar ();
        exit(0);
    }
    else       
    {    
        printf("parent %d\n",getpid());
        printf("I am parent, I done my job\n");
//        wait(1);
    }
    return 0;
}
