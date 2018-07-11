#include<stdio.h>
#include"header.h"

int left_rotate_n_bits (int num, int n)
{
	int bit, pos;
	
	for(pos=0;pos<n;pos++) {	//raotating the num for n times
	bit = (num>>size) & 1;
	num = num<<1;
	num = num | bit;
	}
	
	return num;
}
