#include <stdio.h>
int main()
{
	int x = 010, y = 9, r;

	r = y ^ ((x ^ y) & -(x < y));

	printf("%d\n", r);
}
