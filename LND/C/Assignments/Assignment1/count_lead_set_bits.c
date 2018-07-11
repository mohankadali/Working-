#include<stdio.h>
#include"header.h"

int count_lead_set_bits (int num)
{
	int res, pos, one=0;
	
	for (pos = size; pos >= 0; pos--) {		//counting the lead set bits
		if ((num>>pos) & 1) {
			one++;
		}else
			break;
	}
	
	res = one;
	return res;
}
