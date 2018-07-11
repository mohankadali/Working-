#include <stdio.h>
#include "add.h"

int main (void)
{
	int num1, num2, res;

	printf ("enter two numbers\n");
	scanf ("%d%d", &num1, &num2);

	res = add (num1, num2);
	
	printf ("result is %d\n", res);

	return 0;
}

