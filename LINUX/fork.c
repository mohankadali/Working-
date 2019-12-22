#include <stdio.h>
#include <unistd.h>

int main()
{

pid_t pid;

pid = fork();

if (pid == 0)
{printf("its child...\n");
printf("child pid ppid%d %d \n",getpid(),getppid());
}else if (pid > 0)
{printf("its parent...\n");
printf("parent pid ppid%d %d \n",getpid(),getppid());
}else
printf("fork failed...\n");


return 0;
}
