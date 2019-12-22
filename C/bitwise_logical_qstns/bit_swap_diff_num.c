#include<stdio.h>
#include"header.h"
int bit_swap_diff_num(int snum, int dnum, int s, int d)
{
	int temp1, temp2, bit1, bit2;
	bit1 = (snum>>s)&1;
	bit2 = (dnum>>d)&1;
	res1 = bit1^bit2;
	temp1 = (res1<<s);
	temp2 = (res1<<d);
	res1 = temp1^snum;
	res2 = temp2^dnum;
	return 0;
}
