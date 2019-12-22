#include	<stdio.h>
#include	<stdlib.h>
int main()
{
	int x, n = 32;
	scanf("%d", &n);
	x = (n & n-1) | (int)log2(n & (-n)) & 1;
	printf("%d \n", x);

	return 0;
}
