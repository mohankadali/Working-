#include <stdio.h>               
#include <unistd.h>       
#include <sys/types.h>                                         
#include <sys/socket.h>             
#include <netinet/in.h>
#include <arpa/inet.h>  
#include <string.h>                   
#include <stdlib.h>



struct st {
    int a;
    char ch;
} obj;
struct sockaddr_in  server;
struct sockaddr_in  client;
int main(void)
{
    char ch;
    int sfd,nsfd;

    //    char a[100],b[100];

    sfd = socket(AF_INET,SOCK_STREAM,0);
    printf("socket...\n");

    server.sin_family = AF_INET;
    server.sin_port =  htons(12345);
    server.sin_addr.s_addr = inet_addr("0.0.0.0");

    bind(sfd,(struct sockaddr * )&server,sizeof   (server));
    printf("bind...\n");

    listen(sfd,5);
    printf("listern...\n");

    int len = sizeof(client);

    nsfd = accept (sfd,(struct sockaddr *)&client,&len);
    printf("iaccept...\n");
    while(1)
    {
        read(nsfd,&obj,100);
        printf("%d\n",obj.a);
        printf("%c\n",obj.ch);

        printf("enter data to transfer to client....\n");
        printf ("servr a value ..");
        scanf ("%d",&obj.a);
        printf ("servr ch value ..");
        scanf ("%c",&obj.ch);

        //       scanf("%s",b);
        write(nsfd,&obj,100);
    }

    return 0;
}

