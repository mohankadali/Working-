                          
#include <stdio.h>               
#include <unistd.h>                                                                 
#include <sys/types.h>                                                              
#include <sys/socket.h>                                                             
#include <netinet/in.h>                                                             
#include <arpa/inet.h>                                                              
#include <string.h>                                                                 
#include <stdlib.h>



struct sockaddr_in  server;
struct sockaddr_in  client;
int main(void)
{
    char ch;
    int sfd,nsfd;

    char a[100];
    char b[100];

    sfd = socket(AF_INET,SOCK_DGRAM,0);
printf("socket is not \n");

    server.sin_family = AF_INET;
    server.sin_port =  htons(12345);
    server.sin_addr.s_addr = inet_addr("0.0.0.0");

    bind(sfd,(struct sockaddr * )&server,sizeof(server));
printf("bind is not \n");

    int len = sizeof(client);
    while(1)
    {
        recvfrom (sfd,b,sizeof(b),0,(struct sockaddr *)&client,&len);
    printf("recei is not \n");


        printf("%s\n",b);

        printf("enter data to transfer to client....\n");
        scanf("%s",a);
        sendto (sfd,a,sizeof(a),0,(struct sockaddr *)&client,len);
    }
    return 0;
}

