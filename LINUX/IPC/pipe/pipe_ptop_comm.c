#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void server (int writefd, int readfd )
{
	char msg[100];
	int n;
	if ( (n = read (readfd, msg, 100)) < 0 )
	{
		perror ("error reading");
		exit(0);
	}
	msg[n] = ' ';
	printf("%d server received from client :%s\n",getpid(),msg);
	printf ("enter the msg to be sent to client: ");
	fgets (msg, 100, stdin);
	write(writefd,msg,strlen(msg)-1);
}
void client (int readfd, int writefd )
{
	char msg[100];
	int n;
	char eof = EOF;
	printf ("%d enter the msg to be sent to server: ",getpid());
	fgets (msg, 100, stdin);
	if ( write (writefd, msg, strlen(msg)-1) == -1 )
	{
		perror ("error writing");
		exit(0);
	}
	if ( (n = read (readfd, msg, 100)) < 0 )
	{
		perror ("error reading");
		exit(0);
	}
	msg[n] = ' ';
	printf("%d received from server :%s\n",getpid(),msg);
}

int main()
{
	int pipe1fd[2],pipe2fd[2];
	int pid;

	if (pipe(pipe1fd) == -1)
	{
		perror("pipe");
		return 0;
	}
	if (pipe(pipe2fd) == -1)
	{
		perror("pipe");
		return 0;
	}
	pid = fork();
	if (pid == 0)
	{
		close(pipe1fd[1]); 
		close(pipe2fd[0]); 
		client (pipe1fd[0],pipe2fd[1]);
		exit(0);
	}
	else
	{
		close(pipe1fd[0]); 
		close(pipe2fd[1]); 
		server (pipe1fd[1],pipe2fd[0]);
		wait(NULL);
	}
	return 0;
}
