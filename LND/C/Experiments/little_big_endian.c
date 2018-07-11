#include<stdio.h>
int main(void)
{
	unsigned int a=0x1234567;
	char *c=(char*)&a;
	printf("*c value is ox%x",*c);
	if(*c==0x67)
	{
		printf("little endian\n");
	}
	else
	{
		printf("big endian\n");
	}
	return 0;
}
