#include"header.h"

void str_cpy(char *dbuff, char *sbuff)
{
	while(*sbuff!='\0')
	{
		*dbuff++=*sbuff++;
	}

	*dbuff='\0';
}	

