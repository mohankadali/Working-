#include	<stdio.h>
#include	<stdlib.h>
static void print_name();
static void print_name()
{
	printf("sudnar\n");
}
void print_name_i()
{
	print_name();
}
int main()
{
	print_name();
	print_name_i();
	return EXIT_SUCCESS;
}
