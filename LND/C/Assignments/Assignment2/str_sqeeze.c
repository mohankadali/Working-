#include "header.h"

void str_squeeze (char *buff)
{
int i, j, len, len1;

for (len = 0; buff[len] != '\0'; len++);

len1 = 0;

for (i = 0; i < (len-len1); )
{
	if (buff[i] == buff[i + 1])
	{
		/*shift all characters*/
		for (j = i; j < (len - len1); j++)
			buff[j] = buff[j + 1];
		len1++;
	}
	else
	{
		i++;
	}
}
}

