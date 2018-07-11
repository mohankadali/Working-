#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
int main() 
{
	int i, j;
	i = (1,2,3);
	printf("\nNumber:%d", i);
	i = 1,2,3;
	printf("\nNumber:%d\n", i);
	return EXIT_SUCCESS;
}
