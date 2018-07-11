#include "header.h"

int str_case_cmp (char *first, char *second)
{
	while(*first==*second)
	{
		if ( *first == '\n' || *second == '\n' )
			break;

		first++;
		second++;
	}
	if( *first == '\n' && *second == '\n' )
		return 0;
return 3;
}
