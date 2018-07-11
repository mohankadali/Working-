#include<stdio.h>
#include"header.h"
int even_bit_toggle(int n)
{
	int result, temp=1, pos;
	for(pos=0; pos<=size; pos=pos+2) {
		temp = temp|(1<<pos);
	}
	result = temp^n;
	return result;
}
