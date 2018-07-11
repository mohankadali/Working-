#include	<stdio.h>
#include	<stdlib.h>
int main()
{
	int x = 0, m, n = 32;
	scanf("%d%d", &m, &n);

	/* x = x | (((1 << (n + 1)) - 1) ^ (1 << m) -1); */
	/* x = x | ((~(~0 << (n + 1))) ^ ~(~0 << m)); */
	x = x | ((~0 << (n + 1)) ^ (~0 << m));

	printf("%08x \n", x);

	return 0;
}
