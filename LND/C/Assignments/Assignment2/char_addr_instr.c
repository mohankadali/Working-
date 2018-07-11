#include"header.h"
int char_addr_instr(char *buff, char ch)
{
	int i;
	for(i=0;buff[i] != '\n'; i++) {
	if(buff[i]==ch) {
			return i;
		//	break;
		}
	}
	return 0;
}
