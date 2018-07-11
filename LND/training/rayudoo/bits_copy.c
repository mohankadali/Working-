#include<stdio.h>
#include"header.h"
int bits_copy(int snum, int dnum, int n, int s, int d)
{
	unsigned int  pos;
	snum = snum>>(s+1-n);
	for(pos=n; pos<size; pos++) {
		snum = snum & ~(1<<pos);
	}
	snum = snum<<(d+1-n);
	for(pos=d; pos>=(d+1)-n; pos--){
		dnum = dnum & ~(1<<pos);
	}
	dnum = snum|dnum;
	return dnum;
}
