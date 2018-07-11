#include<stdio.h>
#include"header.h"

int right_rotate_n_bits (int num, int n)
{
	int bit, pos;
	
	for(pos=0; pos<n; pos++) {		//rotating num to right for n times
	bit = num & 1;
	num = num>>1;
	num = num ^ (1<<size);
	bit = bit<<size;
	num = num | bit;
	}
	return num;
}
