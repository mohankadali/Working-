#include "header.h"

int alph_order(char *str)
{
	int i, j, len;
	char temp;
	len = str_len(str);
	printf("%d\n",len);
	for(i = 0; i < len; i++) {
		for(j = 0; j < len; j++) {
			if(str[i] < str[j]) {
				temp = str[j];
				str[j] = str[i];
				str[i] = temp;
			}
		}
	}
	return 0;

}
