#include "header.h"

char str_rev (char *buff, char *revv)
{
	int len, i,j;

	for(len = 0; buff[len] != '\n'; len++);

	printf("%d\n",len);

	for(i=0,j=len;buff[i];i++,j--)
	{
		revv[i]=buff[j];
	}
	revv[i]='\0';
//printf("%s\n",revv);
//		  return revv;
return 0;
}
