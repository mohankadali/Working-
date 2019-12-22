#include	<stdio.h>
#include	<stdlib.h>
int main() 
{
	int var;
	int *ptr;
	ptr = &var;
	printf("%u %u\n", ptr, ptr + 10);
	return EXIT_SUCCESS;
}
