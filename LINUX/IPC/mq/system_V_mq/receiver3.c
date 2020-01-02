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

	long int msg_type;
	int msqid,i,r;
	printf("Opening the Message Queue \n");
	msqid = msgget(10,IPC_CREAT);
	system("ipcs -q"); 
	for(i=0;i<4;i++)
	{
			printf("Enter the Mtype:");
			scanf("%ld",&msg_type);

			r=msgrcv(msqid,&rcv,3,msg_type,MSG_NOERROR);
			//r=msgrcv(msqid,&rcv,3,msg_type,0);
			if(r < 0)
			{
				perror("msgrcv fails");
				exit(1);
			}
			if(r>0)
			{
				printf("MSG: %s\n",rcv.mtext);
				system("ipcs -q");
			}
			memset(rcv.mtext,'\0',sizeof(rcv.mtext));
	}
	//msgctl(msqid,IPC_RMID,0);
	return 0;
}
