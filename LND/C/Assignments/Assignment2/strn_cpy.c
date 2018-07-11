#include"header.h"
void strn_cpy(char *dbuff, char *sbuff, int n)
{
	while(n)
	{

		*dbuff++=*sbuff;
		*sbuff++;
		n--;
	}
*dbuff='\0';
}	

