#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

struct sockaddr_in server;
static char MSG[100];
static char MSG1[100];

int main(int argc,char *argv[])
{
	int sockfd;
	int ch;
	
	if(argc!=3)
	{
		printf("\nUsage:<./cli> <server ip addrs> <server portno>\n");
		return 1;
	}
	/*Fill the info about server */

	server.sin_family 	= AF_INET;
	server.sin_port   	= htons(atoi(argv[2]));
	server.sin_addr.s_addr  = inet_addr(argv[1]);


	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("ERROR:couldn't create socket \n");
		exit(1);
	}
	if(connect(sockfd,(struct sockaddr *)&server,sizeof(server))<0)
	{
		perror("ERROR: connect failed \n");
		exit(1);
	}
	while(1)
	{
		printf("\n\n\t\t\t1.SEND\n");
		printf("\n\n\t\t\t2.RECV\n");
		printf("\n\n\t\t\t3.EXIT\n");
		printf("\n\n\t\t\tEnter U r choice:");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
				__fpurge(stdin);
				printf("\n\n\t\t\tEnter the data to Send:");
				fgets(MSG,100,stdin);		
				send(sockfd,MSG,strlen(MSG)+1,0);
				break;
			case 2:	
				recv(sockfd,MSG1,sizeof(MSG1),0);
				printf("\n\t Received From Server = %s\n",MSG1);
				break;
			case 3:
				close(sockfd);
				exit(0);
		}
	}
}

