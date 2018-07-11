#include<stdio.h>
#include <time.h>
#include <mqueue.h>
#include<stdlib.h>
int main (void)
{
	char *p = (char*)malloc(sizeof(char)*20);
	int x;
	mqd_t  q1;
	q1 = mq_open("/msg1",O_WRONLY | O_CREAT , 0666, NULL);
	if(q1 < 0)
	perror("que failed");
	printf("enter message to send\n");
	scanf("%s",p);
	x = mq_send(q1 ,p,20,4);
	if(x < 0)
	perror("que failed");
//	mq_close(q1);
}
