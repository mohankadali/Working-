#include <stdio.h>
int main()
{
	float x = 0.25;
	char *ptr = (char *)&x;

	scanf("%f", &x);

	printf("%02X %02X %02X %02X\n", ptr[0], ptr[1], ptr[2], ptr[3]);
}
