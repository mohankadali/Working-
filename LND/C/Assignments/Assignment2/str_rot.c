#include "header.h"

int str_rot (char *buf, char *rbuf)
{
	char ch;
	int len, i, j, count=0;
	for(len = 0; buf[len] != '\n'; len++);
	ch=buf[len-1];
	for(i = (len - 1); i > 0; i--)
	{
		buf[i] = buf[i-1];
	}
	buf[0]=ch;
	buf[len] = '\0';
//	printf("%s\n",buf);

	for(i = 0, j = 0; buf[i]; i++, j++) {
		if(buf[i]==rbuf[j]) {
			count=count+1;
		}
	}
//	printf("%d\n",count);
//	printf("%d\n",len);
	if(count == len)
		return 1;
	else
		return 0;

}

