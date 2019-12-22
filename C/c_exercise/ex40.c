#include	<stdio.h>
#define CHAR_BIT 8
int min(int a, int b)
{
    a -= b;
//    a &= a >> 31;
    a &= a >> (CHAR_BIT * sizeof(int) - 1);
    a += b;
    return a;
}
int main() 
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);	
	printf("Min:%d\n", min(a,min(b,c)));
}
