#include <stdio.h>
int * foo()
{
static	int a = 5;
	return &a;
}

int main()
{
	int* p = foo();
	printf("%d\n",*p);
//	*p = 8;
//	printf("%d\n",*p);
}
