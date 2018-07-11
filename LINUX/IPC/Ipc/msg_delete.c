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
	
	printf("Creating a Message Queue \n");
	msqid = msgget(0x20,IPC_CREAT|0666);
	
	printf("Message Queue ID = %d\n",msqid);
	system("ipcs -q");

	printf("Deleting the MQ \n");
	msgctl(msqid,IPC_RMID,0); 
	
	system("ipcs -q");
}
