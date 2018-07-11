#include <stdio.h>
void foobar1(void)
{
	printf("In foobar1\n");
}

void foobar2()
{
	printf("In foobar2\n");
}

int main()
{
	char ch = 'a';
	int a;
	foobar1();
	foobar2(33, ch, a);
	return 0;
}
