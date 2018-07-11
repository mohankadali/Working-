#include<stdio.h>
#pragma pack(1)
int main(void)
{
	struct frame
	{
		int ver:4;
		int head:4;
		int serv:8;
		int tot:16;
		int id:16;
		int fl:4;
		int frgof:12;
		int ttl:7;
		int pt:9;
		int headch:16;
		int src;
		int dest;
		int opt:28;
	}fm;

printf("size of struct frame is %d\n",sizeof(fm));
return 0;
}
