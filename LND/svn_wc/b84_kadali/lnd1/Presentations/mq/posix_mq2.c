#include<stdio.h>
#include <time.h>
#include <mqueue.h>
#include<stdlib.h>
int main (void)
{
	char *p = (char*)malloc(sizeof(char)*20);
	ssize_t  x;
	mqd_t  q1;
//	int *x = 1;
	q1 = mq_open("/msg1",O_RDONLY , 0666, NULL);
	if(q1 < 0)
	perror("que failed");
//	scanf("%s",p);
	x = mq_receive(q1 ,p,9000,NULL);
	if(x < 0)
	perror("receive failed");
	printf("%s\n",p);
//	mq_close(q1);
}
