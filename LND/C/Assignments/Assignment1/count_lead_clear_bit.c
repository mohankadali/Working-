#include<stdio.h>
#include "header.h"

int count_lead_clear_bits (int num)
{
	int res, pos, zero=0;
	for (pos = size; pos >= 0; pos--) {		//counting the lead clear bits
		if (!((num>>pos) & 1)) {
			zero++;
		}else
			break;
	}
	res = zero;
	return res;
}
