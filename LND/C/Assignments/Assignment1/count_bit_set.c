#include<stdio.h>
#include"header.h"

int count_bit_set(int num)
{
	int res, pos, one=0;
	
	for(pos=0; pos<=size; pos++) {		//counting the set bits
		if((num>>pos)&1){
			one++;
		}
	}
	
	res = one;
	return res;
}
