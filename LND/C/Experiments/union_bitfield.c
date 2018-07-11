#include<stdio.h>

int showbits(int);

int main (void)
{
	union A
	{
		int a;
		short int b;
		char s;
	}val={5};

	printf ("size of union %d\n", sizeof(val));
	printf ("size of a is %d\n", showbits(val.a));
	printf ("size of b is %d\n", showbits(val.b));
return 0;
}
int showbits(int n)
{
	int i;
	for((i=8*sizeof(int))-1;i>0;i--) {
		printf("%d",((n>>i)&1));
	}
}
