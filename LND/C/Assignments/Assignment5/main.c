#include<stdio.h>
#include "header.h"

int main(void)
{
	int qn;
	int ch;
	printf("enter qn number\n");
	fgets((char*)&ch,2,stdin);
	qn=atoi((char*)&ch);
	
	switch(qn)
	{
		case 1:
			up_to_low();
			break;
		case 2:
			search_str();
			break;
		case 3:
			rem_cmnt();
			break;
		case 4:
			cnt_word();
			break;
		case 5:
			write_struct();
			break;
		case 6:
			read_struct();
			break;
		default:printf("incorrect enter\n");
	}
return 0;
}
