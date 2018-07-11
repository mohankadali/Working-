#include<stdio.h>
#include<string.h>
int main(void)
{
	char *buff="hello",*buf="raju";
		memcpy(buff,buf,3);
	printf("%s\n",buff);
	return 0;
}
