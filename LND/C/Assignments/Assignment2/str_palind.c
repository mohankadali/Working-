#include "header.h"

int str_palindrm (char *buff)
{
	int len, i, j,count=0;
	char revv[100];
	
	for(len = 0; buff[len] != '\n'; len++);
	printf("%d\n",len);
	
	for(i = 0, j = len-1; buff[i] !='\n'; i++, j--)
	{
		revv[i] = buff[j];
	}
	revv[i] = '\0';
	printf("%s\n",revv);

 for(i = 0, j = 0; buff[i]; i++, j++) {
		if(buff[i]==revv[j]) {
			count=count+1;
		}
	}
printf("%d\n",count);
printf("%d\n",len);
	if(count == len)
		return 1;
	else
		return 0;

}

