#include<stdio.h>
#include"header.h"
int count_tail_set_bits(int num)
{
	int res, pos, one=0;
	for(pos=0; pos<=size; pos++) {
		if((num>>pos)&1) {
			one++;
		} else
			break;
	}
	res = one;
	return res;
}
