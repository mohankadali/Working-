#include "header.h"

int str_spn (char *dbuff, char *sbuff)
{
	int i, count=0;

	for (i = 0; sbuff[i]; i++) {
			if (sbuff[i] == dbuff[i]) {
				count=count+1;
			}
			else
				break;
	}		
return count;
}

