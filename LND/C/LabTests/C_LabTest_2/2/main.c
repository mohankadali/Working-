#include "header.h"
//int str_len (char *);
//int alph_order(char *);
char buf[100];
int len;

int main (void)
{
	printf ("enter string\n");
	fgets (buf, 100, stdin);
	
	len = str_len (buf);
	
	alph_order (buf);
	
	fputs (buf, stdout);

	return 0;
}
