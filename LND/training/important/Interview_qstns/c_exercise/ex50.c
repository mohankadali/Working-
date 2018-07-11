#include	<stdio.h>
int main()
{
	int a[][3] = {1, 2, 3, 4, 5, 6};
	int *ptr;
	ptr = a + 1;
	printf("\na = %u ptr = %u\n", a, ptr);
	ptr = ptr + 1;
	printf("\na = %u ptr = %u\n", a, ptr);
	ptr = a[0] + 1;
	printf("\na[0] = %u ptr(0) = %u\n", a[0], ptr);
	ptr = a[1] + 1;
	printf("\na[1] = %u ptr(1) = %u\n", a[1], ptr);
	ptr = &a[0] + 1;
	printf("\na[0] = %u &ptr(0) = %u\n", &a[0], ptr);
	ptr = &a[1] + 1;
	printf("\na[1] = %u &ptr(1) = %u\n", &a[1], ptr);
}
