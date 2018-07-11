#include<stdio.h>
#include"header.h"
int setbits_rightmost(int snum,int dnum, int n, int s)
{
	unsigned int ref, pos;
	ref = dnum;
	for(pos=n; pos<=size; pos++)
	{
		ref = ref&~(1<<pos);
	}
	ref = ref<<(s+1-n);
	for(pos=s+1-n;pos<=s;pos++)
	{
		snum=snum&~(1<<pos);
	}
	snum = ref|snum;
	return snum;
}
