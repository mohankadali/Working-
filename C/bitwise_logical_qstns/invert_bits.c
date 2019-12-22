#include<stdio.h>
#include"header.h"
int invert_bits(int num, int n, int posn)
{
	unsigned int pos;
	for(pos=posn+1-n; pos<=posn; pos++) {
		num = num^(1<<pos);
	}
	return num;
}
