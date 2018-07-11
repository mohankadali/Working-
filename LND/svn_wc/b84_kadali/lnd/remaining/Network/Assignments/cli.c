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
} obj ;



struct sockaddr_in  server;
int main(void)
{
    char ch;
    int sfd,nsfd;

  //  char a[100],b[100];

    sfd = socket(AF_INET,SOCK_STREAM,0);


    server.sin_family = AF_INET;
    server.sin_port =  htons(12345);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect (sfd,(struct sockaddr *)&server,sizeof(server));

    while(1)
    {


        printf("enter data to transfer to server....\n");
        //    scanf("%s",b);i
        printf ("servr a value ..");                     
        scanf ("%d",&obj.a);  
        printf ("servr ch value ..");
        scanf (" %c",&obj.ch);

        write(sfd,&obj,100);


        read(sfd,&obj,100);
        //        printf("%s\n",b);
        printf("%d\n",obj.a); 
        printf("%c\n",obj.ch);

    }
    return 0;
}

