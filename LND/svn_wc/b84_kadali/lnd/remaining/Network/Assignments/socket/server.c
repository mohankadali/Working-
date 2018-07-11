

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_CONNECTIONS 5

struct sockaddr_in server;
struct sockaddr_in client;
socklen_t len;
char MSG[100];
char MSG1[50];

int main(int argc,char *argv[])
{
	int sockfd,newsockfd,ch;
	
	
	if(argc!=2)
	{
		printf("\n Usage : <./ser> <server port no> \n");
		return 1;
	}	
	/* server is binding itself */
	server.sin_family = AF_INET;
	server.sin_port   = htons(atoi(argv[1]));
	server.sin_addr.s_addr = htonl(INADDR_ANY);
//	server.sin_addr.s_addr = inet_addr("192.168.0.145");

	
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("ERROR:couldn't create socket \n");
		exit(1);
	}
	if(bind(sockfd,(struct sockaddr *)&server,sizeof(server))<0)
	{
		perror("ERROR: bind fails \n");
		exit(1);
	}
	listen(sockfd,MAX_CONNECTIONS);
	printf("\n Waiting For client Connection........ \n");
	len = sizeof(client);
	newsockfd = accept(sockfd,(struct sockaddr *)&client,&len);
	while(1)
	{
		printf("1.SEND\n");
		printf("2.RECV\n");
		printf("3.EXIT\n");
		printf("Enter U r Choice:    ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				__fpurge(stdin);
				printf("Enter the data to Send:  \n");
				fgets(MSG,100,stdin);
				send(newsockfd,MSG,strlen(MSG)+1,0);
				break;
			case 2:
				printf("Client IP address = %s\n",inet_ntoa(client.sin_addr));	
				recv(newsockfd,MSG1,sizeof(MSG1),0);
				printf(" Received : %s\n",MSG1);
				break;
			case 3:
				close(newsockfd);
				close(sockfd);
				exit(0);
		}
	}
}
				
		

		

	
 


