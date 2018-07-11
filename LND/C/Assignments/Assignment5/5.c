#include <stdio.h>
#include "header.h"

struct st
{
	unsigned char e_ident[16];
	int e_type;
	int e_machine;
	unsigned int e_entry;
};

int write_struct()
{
	FILE *fptr;
	int i ;
	struct st e[2];
	
	fptr = fopen ("info.db","w");
	
	for (i = 1; i <= 2; i++)
	{
		printf ("enter the e_ident: ");
		scanf ("%s",e[i].e_ident);

		printf ("enter the e_type: ");
		scanf ("%d",&e[i].e_type);

		printf ("enter the e_machine: ");
		scanf ("%d",&e[i].e_machine);

		printf ("enter the e_entry: ");
		scanf ("%d",&e[i].e_entry);

		fwrite (&e[i],sizeof(e[i]),2,fptr);
	}
	printf ("successfully recoreded data\n");
	fclose (fptr);
	return 0;
}


