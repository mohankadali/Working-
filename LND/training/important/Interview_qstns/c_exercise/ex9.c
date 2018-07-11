#include	<stdio.h>
char * func(char *s)
{
	char str[] = "Edge";
	s = str;
	return s;
}
int main()
{
	char s[] ="Global";
	printf("%s\n", s);
	s = func(s);
	printf("%s\n", s);
	return 0;
}
