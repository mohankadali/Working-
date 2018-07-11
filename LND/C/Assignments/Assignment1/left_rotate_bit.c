#include <stdio.h>
#include "header.h"

int left_rotate_bit (int num)
{
	int bit;
	bit = (num>>size)&1;
	num = num<<1;
	num = num|bit;
	return num;
}
