#include <stdio.h>
#include <unistd.h>
int main(void)
{
        int fd[2];
        char str[100];

        pipe(fd);  //creating pipe

        pid_t pid = fork();
        if(pid > 0){  // parent process
                sleep(1);
                printf("in parent enter data\n");
                fgets(str, 20, stdin);
                write(fd[1], str, sizeof(str));
                //        		close(fd[1]);
                //        		close(fd[0]);
                wait(0);
                read(fd[0], str, sizeof(str));
                printf("parent received: %s\n", str);
        }
        else if(pid == 0){ //child process
                printf(" child  is waiting ...\n");
                read(fd[0], str, sizeof(str));
                printf("child received: %s\n", str);
                printf("in child enter data\n");
                fgets(str, 20, stdin);
                // 		close(fd[1]);
                write(fd[1], str, sizeof(str));
                //		close(fd[0]);
        }
        return 0;
}

