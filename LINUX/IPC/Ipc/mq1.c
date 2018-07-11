#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
struct msg
{
	long int mtype;
	char mtext[100];
}snd,rcv;
int main(void)
{
	int msqid,n,i;
	msqid = msgget(10,IPC_CREAT);
	if(msqid == -1)
	{
		perror("msgget fails");
		exit(1);
	}
	printf("Message queue is created successfully\n");
	snd.mtype=1;
	rcv.mtype=2;
	while(1)
	{
	
		printf("Enter the mtext:");
		__fpurge(stdin);
		gets(snd.mtext);
		msgsnd(msqid,&snd,sizeof(snd),0);

		msgrcv(msqid,&rcv,sizeof(rcv),rcv.mtype,0);
		printf("%s\n",rcv.mtext); 
	}
 
	return 0;
}
