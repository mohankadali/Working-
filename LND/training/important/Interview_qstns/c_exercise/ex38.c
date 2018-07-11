#include<stdio.h>
unsigned char test_endian( void )
{
    int test_var = 0x1;
    unsigned char *test_endian = (unsigned char*)&test_var;

    return (test_endian[0] == NULL);
}
int main()
{
	if (test_endian())
		printf("big endian\n");
	else
		printf("little endian\n");
		
    return 0;
}
