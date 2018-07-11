#include <stdio.h>

void foo(int[3][3]);

int main(void)
{
	int a[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	// int a[3];

	printf("%02X\n", a[0]);

	printf("%02X\n", &a[1][0] );

	foo(a);
	// printf("%d %d\n", a[1][1], a[2][1]);

	return 0;
}

void foo(int b[3][3])
{
	++b;	
	printf("%02X\n", b );
	b[1][1] = 9;
}

