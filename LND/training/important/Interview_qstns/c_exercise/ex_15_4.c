#include <stdio.h>

int main()
{
	char s[100] = "123456789";
	char *e = s;

	/* memcpy (d, s + 3, sizeof(int)); */
	/* memmove (e + 3, s, 10); */
	memcpy (e + 4, s, 5);

	/* printf("%s\n", d); */
	printf("%s\n", e);
}
