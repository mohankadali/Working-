#include<stdio.h>

union endian
{
	int a;
	char ch;
}u1;

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

struct frame1
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
}fm1;

struct frame2
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
}fm2;

union sample
{
	int a:5;
	int b:10;
	int c:5;
	int d:21;
	int e;
}s1;
int main(void)
{
	
	u1.a = 0x12345678;

	if ((*(char*)&u1.a) == 0x78)
		printf ("little endian\n");
	else
		printf ("big endian\n");

	printf("size of struct frame is %d\n",sizeof(fm));

	printf("size of struct frame is %d\n",sizeof(fm1));

	printf("size of struct frame is %d\n",sizeof(fm2));

	s1.e=128;
	printf("size of union is %d\n",sizeof(s1));
	printf("value of a is %d\n",s1.a);
	printf("value of b is %d\n",s1.b);
	printf("value of c is %d\n",s1.c);
	printf("value of d is %d\n",s1.d);	   
	printf("value of e is %d\n",s1.e);

	return 0;
}
