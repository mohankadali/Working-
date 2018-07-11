#include "header.h"

char insert_char (char *buf, char chr, int pn)
{
	int len, i;
	for (len = 0; buf[len] != '\n'; len++);
	printf ("length %d\n", len);
if(len>=pn)
{
	for(i=len+1;i>=pn;i--)
	{
		buf[i+1]=buf[i];
	}
	buf[pn]=chr;
}
//	printf("%s\n",ref);
return 0;

}

