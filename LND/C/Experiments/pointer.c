#include<stdio.h>

int main(void)
{
	int a=10,b=20,c[10]={1,2,3,4,5,6,7};
	int *ptr;
	ptr=&a;
	printf("%d\n",*ptr);
	b=*ptr;
	printf("%d\n",b);
	*ptr=0;
	printf("%d\n",*ptr);
	ptr=&c[0];
printf("%d\n",*ptr);
}	

