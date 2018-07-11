#include<stdio.h>
int main(void)
{
	int hex;
	int bin,i;
	printf("hexa to bin coversion\n");
	printf("enter hex n umber\n");
	scanf("%x",&hex);
	for(i=31;i>=0;i--)
	{
		bin= (hex>>i)&1;
		printf("%d",bin);			
	}
	printf("\n");
}
