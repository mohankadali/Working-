#include "header.h"

int str_len(char *str)
{
	int i;
	for (i=0; str[i]; i++);
	return i;
}

