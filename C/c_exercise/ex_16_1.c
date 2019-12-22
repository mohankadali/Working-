#include <stdio.h>
int fun1()
{
	printf("fun1\n");
	return 0;
}
int fun2()
{
	printf("fun2\n");
	return 0;
}
int fun3()
{
	printf("fun3\n");
	return 0;
}

int main()
{
	printf("%d", fun1() + fun2() * fun3());
}
