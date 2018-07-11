#include<stdio.h>
//#pragma pack(1)
int main(void)
{
	struct frame
	{
		char vpi1:4;
		char gfc:4;
		char vci1:4;
		char vpi2:4;
		short int vci2:8;
		char clp:1;
		char  :1;
		char pti:1;
		char  :1;
		char vci3:4;
		short int hec:8;
	}fm;

printf("size of struct frame is %d\n",sizeof(fm));
return 0;
}
