#include	<stdio.h>
int main()
{
	int a[] = {1,2,3,4,5};
	int *ptr;
	ptr = &a + 1;
	printf("\na = %u ptr = %u\n", a, ptr);
	ptr = &a[0] + 1;
	printf("\na = %u ptr(0) = %u\n", a, ptr);
	ptr = &a[1] + 1;
	printf("\na = %u ptr(1) = %u\n", a, ptr);
	ptr = &a[2] + 1;
	printf("\na = %u ptr(2) = %u\n", a, ptr);
}
