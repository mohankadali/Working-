#include<stdio.h>

int main (void)
{
	union endian 
	{
	int a;
	char ch;
	}u1;

u1.a = 0x12345678;

if ((*(char*)&u1.a) == 0x78)
	printf ("little endian\n");
	else
		printf ("big endian\n");

return 0;
}
