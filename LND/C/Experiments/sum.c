#include<stdio.h>
void sum(int a,int b);
int main(void)
{
	int a,b;
	sum(a,b);
	return 0;
}

void sum(int a,int b)
{
	int s;
	printf("enter values\n");
	scanf("%d%d",&a,&b);
	s=a+b;
	printf("sum is %d\n",s);
}
