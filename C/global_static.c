#include <stdio.h>
//static int i = 3;
static void staticDemo()
{
	static int i;
	printf("%d\n", i);
	i++;
	{
		printf("%d\n", i);
		i++;
	}
}

int main()
{
	staticDemo();
	staticDemo();
}

