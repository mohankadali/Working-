#include<stdio.h>
#define size ((sizeof(int)*8)-1)
#define max_min_nums(num1, num2) { int temp;\
	temp = num1-num2;\
	temp = (temp>>size)&1;\
	if(temp)\
	{\
		printf("max is %d\n", num2);\
	}\
	else\
	{\
		printf("max is %d\n", num1);\
	}\
}
#define set_bit(num, posn) { int temp;\
	temp = num;\
	temp = temp|(1<<posn);\
}
#define clear_rightmost_set(num) {int temp;\
	temp = num;\
	(temp = (temp&(temp-1)));\
	printf("after clearing rightmost set bit num is %x\n", temp);\
}
#define set_rightmost_clear(num) {int temp;\
	temp = num;\
	temp = temp|(temp-1);\
	printf("after setting rightmost clear bi num is %x\n", temp);\
}
#define clear_leftmost_set(num) { int temp, ref;\
	ref = num;\
	for(temp=size; temp>=0; temp--) {\
		if((ref>>temp)&1) {\
			ref = ref&~(1<<temp);\
			break;\
		}\
	}\
	printf("after clearing leftmost set bit num is %x\n", ref);\
}
#define set_leftmost_clear(num) { int temp, ref;\
	ref = num;\
	for(temp=size; temp>=0; temp--) {\
		if(!((ref>>temp)&1)) {\
			ref = ref^(1<<temp);\
			break;\
		}\
	}\
	printf("after setting leftmost clear bit num is %x\n", ref);\
}
#define set_range_bits(num, s, d) { int  temp, ref;\
	ref = num;\
	ref = 0;\
	for(temp=s; temp>=d; temp--) {\
		ref = ref|(1<<temp);\
	}\
	printf("after setting bits from sourse to dest position num is %x\n", ref);\
}
#define clear_range_bits(num, s, d) { int temp, ref;\
	ref = num;\
	ref = ~0;\
	for(temp=s; temp>=d; temp--) {\
		ref = ref^(1<<temp);\
	}\
	printf("after clearing bits from source to dest position num is %x\n", ref);\
}
#define toggle_range_bits(num, s, d) { int temp, ref;\
	ref = num;\
	for(temp=s; temp>=d; temp--) {\
		ref = ref^(1<<temp);\
	}\
	printf("after toggling bits from source to dest position num is %x\n", ref);\
}
#define getbits_leftadj(num, n, posn) {int temp, ref; \
	ref = num;\
	ref=ref>>(posn-1);\
	for(temp=(n+posn); temp<=size; temp++) {\
		ref = ref&~(1<<temp);\
	}\
	printf("getting bits from num is %x\n", ref);\
}
int res1,res2;
int bit_swap(int, int, int);
int bit_swap_diff_num(int, int, int, int);
int bits_copy(int, int, int, int, int);
int even_bit_toggle(int);
int odd_bit_toggle(int); 
int left_rotate_bit(int);
int right_rotate_bit(int);
int left_rotate_n_bits(int, int);
int right_rotate_n_bits(int, int);
int count_bit_set(int);
int count_bit_clear(int);
int count_lead_set_bits(int);
int count_lead_clear_bits(int);
int count_tail_set_bits(int);
int count_tail_clear_bits(int);
int setbits_rightmost(int, int, int, int);
int invert_bits(int, int, int);

