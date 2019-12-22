#include<stdio.h>
#include"header.h"
int bit_swap(int num, int s, int d)
{
	int result, bit1, bit2;
	bit1 = (num>>s)&1;
	bit2 = (num>>d)&1;
	result = bit1^bit2;
	result = (result<<s)|(result<<d);
	result = result^num;
	return result;
}
