#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct msg
{
	long int mtype;
	char mtext[100];
}rcv;

int main(void)
{

	pid_t pid;long int msg_type;
	int msqid,i,r;
	printf("Accessing  the Message Queue \n");
	msqid = msgget(66,IPC_CREAT); 
	for(i=0;i<3;i++)
	{
		printf("Enter the Mtype:");
		scanf("%ld",&msg_type);

		r=msgrcv(msqid,&rcv,sizeof(rcv),msg_type,IPC_NOWAIT);
		if(r>0)
		{
			printf("MSG: %s\n",rcv.mtext);
		}
		//memset(rcv.mtext,'\0',sizeof(rcv.mtext));
	}
	return 0;
}
