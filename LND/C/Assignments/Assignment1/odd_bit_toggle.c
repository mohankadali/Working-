#include<stdio.h>
#include"header.h"

int odd_bit_toggle (int n)
{
	int result, temp=1, pos;
	
	for(pos = 1; pos <= size; pos = pos + 2) {		//toggling odd bits
		temp = temp ^ (1<<pos);
	}
	result = temp ^ n;
	result = result ^ 1;
	return result;
}
