#include <stdio.h>
int main()
{
	char s[100] = "Gl";
	char *p = "edge";

	sprintf(s,"%s %s",p, s);

	printf("%s\n", s);
}
