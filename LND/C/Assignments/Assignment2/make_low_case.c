#include "header.h"

int make_lo_case(char *str)
{
	int i;
	for(i=0;str[i];i++) {
		if(str[i]>='A' && str[i]<='Z')
			str[i]=str[i]+32;
		else
			str[i]=str[i];
	}
return 0;
}

