/**********************************************************************
*Program Name : Communication b/w Unrelated Process Using Message Queus		
***********************************************************************/

#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
void send1(int);
void receive(int);

struct msgbuf
{
	long mtype;
	char mtext[100];
}send,recv;

int main(void)
{

	int msgid; /*Message Queue Identifier*/
	size_t len; /*len of the message*/
	key_t key = 0x80;

	/**************Creating the Message Queue**********************/

 	msgid = msgget(key,IPC_CREAT|0666);
	if (msgid < 0)
	{
		fprintf(stderr,"msgget failed");	
		exit(-1);
	}
	
	int ch;
	while(1)
	{
		printf("\n\t1.send\n");
		printf("\n\t2.receive\n");
		printf("\n\t3.exit\n");
		printf("\n\tEnter the choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:send1(msgid);
				break;

			case 2:receive(msgid);
				break;
			
			default:exit(0);
		}
	}
}
	/*************Receiving The Message*******************************/
	void receive(int msgid)
	{
		long pri;
		memset(&recv,'\0',sizeof(recv));
		printf("\n\tEnter the priority:");
		scanf("%ld",&pri);
		msgrcv(msgid,&recv,sizeof(recv),pri,0);
		printf("\n\tReceived = %s\n",recv.mtext);
	}
			 
	/*************Sending The Message*******************************/
	void send1(int msgid)
	{
		printf("\n\tEnter The Priority of The Message:");
		scanf("%ld",&send.mtype);

		printf("\n\tEnter The Message To Send:");
		__fpurge(stdin);
		fgets(send.mtext,100,stdin);	
		msgsnd(msgid,&send,sizeof(send),0);
	}

