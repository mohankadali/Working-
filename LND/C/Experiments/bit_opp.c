#include<stdio.h>
int main(void)
{
	signed char a=-12;
	unsigned char b=12;
	printf("a shifted left by 4 times is %d\n",a<<4);
	printf("a shifted right by 4 times is %d\n",a>>4);
	printf("b shifted left by 4 times is %d\n",b<<4);
	printf("b shifted right by 4 times is %d\n",b>>4);
	return 0;
}
