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
	struct msqid_ds buf;

	msqid = msgget(10,IPC_CREAT|0666);
	if(msqid == -1)
	{
		perror("msgget fails");
		exit(1);
	}
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
	printf("Message Queue info ..msgctl() \n");
	msgctl(msqid,IPC_STAT,&buf);
	printf("current no of msgs in the queue=%d\n",buf.msg_qnum);
	printf("Maxinum no of bytes allowed in the queue=%d\n",buf.msg_qbytes);
	printf("pid of last msgsnd=%d\n",buf.msg_lspid);
	printf("Time of last msgsnd =%s\n",ctime(&buf.msg_stime));
	printf("Time of last msgrcv =%s\n",ctime(&buf.msg_rtime));
	printf("Time of last change =%s\n",ctime(&buf.msg_ctime));

	return 0;
}



