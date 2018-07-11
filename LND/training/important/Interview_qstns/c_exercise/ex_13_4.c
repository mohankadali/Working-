#include <stdio.h>
void func(char **s)
{
	*s = "world";
}
int main()
{
	char *s = "hello";
	func(&s);
	printf("%s\n", s);
}
