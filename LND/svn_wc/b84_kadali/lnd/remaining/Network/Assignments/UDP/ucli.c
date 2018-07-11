
#include <stdio.h>  
#include <unistd.h>                                                             
#include <sys/types.h>                                                          
#include <sys/socket.h>                                                         
#include <netinet/in.h>                                                         
#include <arpa/inet.h>                                                          
#include <string.h>                                                             
#include <stdlib.h> 



struct sockaddr_in  server;
//struct sockaddr_in  client;
int main(void)
{
    char ch;
    int sfd,nsfd;

    char a[100];
    char b[100];

    sfd = socket(AF_INET,SOCK_DGRAM,0);


    server.sin_family = AF_INET;
    server.sin_port =  htons(12345);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int len = sizeof(server);
    while(1)
    {
        printf("enter data to transfer to server....\n");
        scanf("%s",a);
        sendto (sfd,a,sizeof(a),0,(struct sockaddr *)&server,len);





        recvfrom (sfd,b,sizeof(b),0,(struct sockaddr *)&server,&len);
        printf("%s\n",b);
    }
    return 0;
}

