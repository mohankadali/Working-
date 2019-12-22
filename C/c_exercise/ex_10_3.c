#include <stdio.h>

int main()
{
	char *p = "sundar";
	char q[] = "pandi";
	int n;

	n = q - p;

	printf("%d\n", n);
	return 0;
}
