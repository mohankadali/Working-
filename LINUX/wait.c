#include <stdio.h>
#include <unistd.h>

int main()
{

	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		printf("its child...\n");
	}else if (pid > 0)
	{
		sleep(1);
		printf("its parent...\n");
		wait(NULL);
		printf("child killed ...\n");
	}else
		printf("fork failed...\n");
	return 0;
}
