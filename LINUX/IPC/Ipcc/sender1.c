#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct msg
{
	long int mtype;
	char mtext[100];
}snd;

int main(void)
{

	long int msg_type;
	int msqid,i,n;
2	printf("Creating a Message Queue \n");
	msqid = msgget(0x20,IPC_CREAT|0666);
	if(msqid==-1)
	{
		perror("msgget fails");
		exit(1);
	}
	printf("Message Queue ID = %d\n",msqid);
	printf("Enter the no.of msgs:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		{
			printf("Enter the Mtype:");
			scanf("%ld",&snd.mtype);
			
			__fpurge(stdin);
			printf("Enter the Mtext:");
			gets(snd.mtext);
		
			msgsnd(msqid,&snd,sizeof(snd),0);
		}
	return 0;
}
