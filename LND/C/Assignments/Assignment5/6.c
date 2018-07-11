#include<stdio.h>
#include "header.h"

struct st
{
	unsigned char e_ident[20];
	int e_type;
	int e_machine;
	unsigned int e_entry;
};
int read_struct()
	{

		FILE *fptr;
		struct st e;
		fptr=fopen("info.db","r");

		fread(&e,sizeof(e),2,fptr);
		printf("%s\n %d\n %d\n %u\n",e.e_ident,e.e_type,e.e_machine,e.e_entry);
		fclose(fptr);
		return 0;
	}


