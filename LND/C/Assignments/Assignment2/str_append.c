#include "header.h"

void str_append (char *dbuff, char *sbuff)
{
	while (*dbuff) {
		*dbuff++;
	}
	*dbuff--;
	
	while (*sbuff) {
		*dbuff++ = *sbuff;
		*sbuff++;
	}
	*dbuff='\0';
}

