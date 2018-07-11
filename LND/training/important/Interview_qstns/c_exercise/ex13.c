#include<stdio.h>
#define DPRINTF(x) printf("%s:%d\n",#x,x)
int main()
{
	int ch = 45;
	char balraj;
	DPRINTF(ch);
	return 0;
}
