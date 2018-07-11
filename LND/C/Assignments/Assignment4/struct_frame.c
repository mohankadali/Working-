#include<stdio.h>
//#pragma pack(2)
int main(void)
{
	struct frame
	{
		int sp:16;
		int dp:16;
		int sn:32;
		int an:32;
		int head:4;
		int  :6;
		int code:6;
		int win:16;
		int chk:16;
		int urg:16;
	}fm;

printf("size of struct frame is %d\n",sizeof(fm));
return 0;
}
