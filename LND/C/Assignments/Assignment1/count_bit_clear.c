#include<stdio.h>
#include"header.h"

int count_bit_clear (int num)
{
	int res, pos, zero=0;
	
	for (pos = 0; pos <= size; pos++) {		//counting the clear bits
		if (!((num>>pos) & 1)) {
			zero++;
		}
	}
	
	res = zero;
	return res;
}
