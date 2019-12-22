#include	<stdio.h>
union flt_num {
	int i;
	float f;
};

int main()
{
	union flt_num fl;
	int a = 0xf34, most_set_bit;

	fl.f = a;
	most_set_bit = ((fl.i & 0x7f800000) >> 23) - 127;

	printf("%d\n", most_set_bit);
}
