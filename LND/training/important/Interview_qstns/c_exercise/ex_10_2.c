#include <stdio.h>
union sample {
	int a:4;
	int b:3;
	char c;
}var;

int main()
{
	var.c = 8;
	printf("%d %d\n", var.b, var.a);
}
