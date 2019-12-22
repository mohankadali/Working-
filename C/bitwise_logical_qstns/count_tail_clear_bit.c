#include<stdio.h>
#include"header.h"
int count_tail_clear_bits(int num)
{
	int res, pos, zero=0;
	for(pos=0; pos<=size; pos++) {
		if(!((num>>pos)&1)) {
			zero++;
		} else
			break;
	}
	res = zero;
	return res;
}
