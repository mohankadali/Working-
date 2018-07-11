#include <stdio.h>

int str_len (char *str)
{
	int i;
	for(i = 0; str[i] != '\n'; i++);
	return i;
}

