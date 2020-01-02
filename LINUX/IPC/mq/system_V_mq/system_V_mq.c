#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct msg
{
	long int mtype;
	char mtext[100];
}snd,rcv;

int main(void)
{

	pid_t pid;long int msg_type;
	int msqid;
	msqid = msgget(IPC_PRIVATE,IPC_CREAT);
	pid = fork();
	if(pid == 0)
	{
		printf("CHILD PROCESS \n");
		snd.mtype = 2;
		strcpy(snd.mtext,"Hello");
		msgsnd(msqid,&snd,sizeof(snd),0);
	}
	else
	{

		wait(NULL);
		printf("PARENT PROCESS \n");
		printf("Enter the Mtype:");
		scanf("%ld",&msg_type);
		msgrcv(msqid,&rcv,sizeof(rcv),msg_type,0);
		printf("PARENT : MSG TEXT IS %s\n",rcv.mtext);

	}
	return 0;
}
