#include<stdio.h>
#include"header.h"

int right_rotate_bit (int num)
{
	int bit;
	
	bit = num & 1;
	num = num>>1;
	num = num ^ (1<<size);
	bit = bit<<size;
	num = num | bit;
	return num;
}
