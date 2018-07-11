#include<stdio.h>
#include <time.h>
#include <mqueue.h>
#include<stdlib.h>
#define MAX 100 


/*struct mq_attr {
               long mq_flags;       /* Flags: 0 or O_NONBLOCK */
               //long mq_maxmsg;      /* Max. # of messages on queue */
               //long mq_msgsize;     /* Max. message size (bytes) */
               //long mq_curmsgs;     /* # of messages currently in queue */
          // }*attr;

int main() 
{
	struct mq_attr *attr;
//	 mq_getattr(q1, attr)
//	ssize_t x;
	char buf[MAX];
	mqd_t  q1;
	/*q1 = mq_open ("/msg1", O_RDONLY , 0666, NULL);
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
	printf("%s", buf);*/
	 mq_getattr(q1,  attr);
	printf ("%lu\n", attr->mq_flags);
	printf ("%lu\n", attr->mq_maxmsg);
	printf ("%lu\n", attr->mq_msgsize);
	printf ("%lu\n", attr->mq_curmsgs);
}   
