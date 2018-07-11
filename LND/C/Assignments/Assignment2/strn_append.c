#include "header.h"

void strn_append (char *dbuff, char *sbuff, int n)
{
	while (*dbuff) {
		*dbuff++;
	}
	*dbuff--;
	
	while (n) {
		*dbuff++ = *sbuff;
		*sbuff++;
		n--;
	}
	*dbuff='\0';
}

