#include<stdio.h>
int str_cmp (char *str1, char *str2)
{
	int i, count=0, len;
	len = str_len (str1);
	for (i = 0; i < len; i++) {
		if (str1[i] == str2[i])
			count= count + 1;
	}
if (count == len)
	return 0;

return 1;
}
