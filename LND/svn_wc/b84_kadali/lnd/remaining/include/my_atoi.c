#include <stdio.h>

int myAtoi (char *str)
{
	int i;
	int res = 0; // Initialize result

	// Iterate through all characters of input string and
	for (i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';

	return res;
}
