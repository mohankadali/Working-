#include <stdio.h>
#if 0
int main()
{
	int a = 0x12345678;
	char *p;
	double *q;
	p = (char*)&a; // we can do lower to upper type casting 
	q = (double*)&a; // we can do lower to upper type casting but what is the use case ?

	printf("%x\n",*p);
	printf("%e\n",*q);
	return 0;
}
#endif
#if 0
int main()
{
	double x = 1.9;
	int y = x + 2;
	printf("%d\n",y);

	return 0;
}
#endif

