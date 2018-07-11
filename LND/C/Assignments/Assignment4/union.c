#include<stdio.h>
int main(void)
{
	union sample
	{
		int a:5;
		int b:10;
		int c:5;
		int d:21;
		int e;
	}u1;

u1.e=128;
printf("size of union is %d\n",sizeof(u1));
printf("value of a is %d\n",u1.a);
printf("value of b is %d\n",u1.b);
printf("value of c is %d\n",u1.c);
printf("value of d is %d\n",u1.d);
printf("value of e is %d\n",u1.e);
return 0;
}
