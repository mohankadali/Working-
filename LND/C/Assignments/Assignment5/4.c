#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "header.h"
int cnt_word()
{
	int c=0,x=0;
	char *a;
	FILE *fptr;
	fptr = fopen("raju.txt","r");
	while(fgetc(fptr)!=EOF){
		c++;
	}
	rewind(fptr);
	a=malloc(c+1);
/*	while((ch=fgetc(fptr))!=EOF)
	{
		if(ch==' '|| ch=='\n')
			x++;
	}*/

	while(fscanf(fptr,"%s",a)!=EOF)
	{
		x++;
	}
	printf("no of cherecters=%d\n",c);
	printf("no of words=%d\n",x);
	fclose(fptr);
	return 0;
}
