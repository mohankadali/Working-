#include<stdio.h>
#include <time.h>
#include <mqueue.h>
#include<stdlib.h>
#define MAX 100 

int main() 
{
    ssize_t x;
    char buf[MAX];
    mqd_t  q1;
    q1 = mq_open ("/msg1", O_RDONLY , 0666, NULL);
    if (q1 < 0) {
        perror ("qu failed");
        return ;
    }
    printf(" msg to recieve");   


    x = mq_receive(q1, buf, 9000, NULL);
    if(x < 0){
        perror("queue failed");    
        exit(0);
    }	
    printf("%s", buf);
    mq_close(q1);
    mq_open ("/msg1", O_WRONLY);	
        printf("enter msg");
    fgets (buf, MAX, stdin);
    x = mq_send(q1, buf, MAX, 6);
    //printf("%s", buf);
    mq_close (q1);
}   
