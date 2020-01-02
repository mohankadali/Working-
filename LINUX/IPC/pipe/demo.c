#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void server (int writefd, int readfd){
	char msg[100];
	int n;
	printf("server\n");
	if ((n = read(readfd, msg, 100)) == -1){
		perror("read");
		exit(0);
	}
	msg[n] = '\0';
	printf("server recieved from client : %s\n",msg);
	printf("enter the string to send client\n");
	fgets(msg, 100, stdin);
	if(write(writefd, msg, strlen(msg)-1) == -1){
		perror ("error writing");
		exit(0);
	}
}
void client (int readfd, int writefd){
	sleep(1);
	char msg[100];
	int n;
	printf("enter the string to send server\n");
	fgets(msg, 100, stdin);
	if(write(writefd, msg, strlen(msg)-1) == -1){
		perror ("error writing");
		exit(0);
	}
	if ((n = read(readfd, msg, 100)) == -1){
		perror("read");
		exit(0);
	}
	msg[n] = '\0';
	printf("client recieved from server : %s\n",msg);
}
int main(){

	int pipe1fd[2], pipe2fd[2];
	int pid;

	if (pipe(pipe1fd) == -1){
		perror("pipe");
		return 0;
	}

	if(pipe(pipe2fd) == -1){
		perror("pipe");
		return 0;
	}

	pid = fork();
	if (pid == 0){
		close(pipe1fd[1]);
		close(pipe2fd[0]);
		client(pipe1fd[0], pipe2fd[1]);
		exit(0);
	}else{
		close(pipe1fd[0]);
		close(pipe2fd[1]);
		server(pipe1fd[1], pipe2fd[0]);
		wait(NULL);
	}

	return 0;
}
