#include<stdio.h> 
#include<stdlib.h> 
int main()
{
    int a=getpid();
    int pid = fork();
    int var ;
    

    if (pid > 0)
    {
    /*    printf("child %d\n",getpid());
        printf("I am child, Go and check who is my parent..\n");
        kill(a,9);
        sleep(10);*/
   
        printf("parent %d\n",getpid());
       // printf("I am parent, I done my job\n");
    //    sleep(10);
       // wait(1);
    }
     umask(0);   
     var = setsid () ;
        if ( var < 0 ) {
            perror("setsid");
            exit(1);
        }
        chdir("/");
        close(0);
        close(1);
        close(2);
        FILE *fp = fopen("file.txt","w+");
        while(1){
        fprintf(fp,"mohan");
        fflush(fp);
        }
        fclose(fp);
    return 0;
}
