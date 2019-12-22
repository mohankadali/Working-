#include <stdio.h>
#include "header.h"                      // including macros and prototype tothe functions

int main(void)                              // main starts from here     
{
	unsigned int snum, dnum, s, d, n, posn, num, num1, num2, qn, res;

	printf("enter the question number(1 to 18)....\n");
	scanf("%d", &qn);

	switch (qn)
	{
		case 1:
			printf ("enter number and sourse and destinarion bits\n");
			scanf ("%x%d%d", &num, &s, &d);
			res = bit_swap (num, s, d);
			printf ("after swaping number is %x\n", res);
			break; 
		case 2:
			printf ("enter source and destination number and sourse and destinarion bits\n");
			scanf ("%x%x%d%d", &snum, &dnum, &s, &d);
			bit_swap_diff_num (snum, dnum, s, d);
			printf ("after swaping numbers are %x %x\n", res1, res2);		
			break; 
		case 3:
			printf ("enter sourse and destination number and no of bits, sourse and d    estination bits\n");
			scanf ("%x%x%d%d%d", &snum, &dnum, &n, &s, &d);
			res = bits_copy (snum, dnum, n, s, d);
			printf ("after copying the dnum is %x\n", res);	 
			break; 
		case 4:
			printf ("enter number to toggle even bits\n");
			scanf ("%x", &num);
			res = even_bit_toggle (num);
			printf ("after toggling even bitsresult is %x\n", res);
			break;
		case 5:
			printf ("enter number to toggle odd bits\n");
			scanf ("%x", &num);
			res = odd_bit_toggle (num);
			printf ("after toggling odd bitsresult is %x\n", res);
			break; 
		case 6:
			printf ("enter number to be rotated\n");
			scanf ("%x", &num);
			res = left_rotate_bit (num);
			printf ("after left rotating number is %x\n", res);
			break; 
		case 7:
			printf ("enter number and no of bits to be left rotated\n");
			scanf ("%x%d", &num, &n);
			res = left_rotate_n_bits (num, n);
			printf ("after left rotating number is %x\n", res);
			break; 
		case 8:
			printf ("enter number to be rotated right\n");
			scanf ("%x", &num);
			res = right_rotate_bit (num);
			printf ("after right rotating number is %x\n", res);
			break; 
		case 9:
			printf ("enter number and no of bits to be rotated right\n");
			scanf ("%x%d", &num, &n);
			res = right_rotate_n_bits (num, n);
			printf ("after right rotating number is %x\n", res);
			break; 
		case 10:
			printf ("enter number\n");
			scanf ("%d", &num);
			res = count_bit_set (num);
			printf ("the number of set bits are %d\n", res);
			break; 
		case 11:
			printf ("enter number\n");
			scanf ("%d", &num);
			res = count_bit_clear (num);
			printf ("the number of clear bits are %d\n", res);
			break; 
		case 12:
			printf ("enter number\n");
			scanf ("%x", &num);
			res = count_lead_set_bits (num);
			printf ("the number of lead set bits are %d\n", res);
			break;
		case 13:
			printf ("enter number\n");
			scanf ("%x", &num);
			res = count_lead_clear_bits (num);
			printf ("the number of lead clear bits are %d\n", res);
			break;
		case 14:
			printf ("enter number\n");
			scanf ("%x", &num);
			res = count_tail_set_bits (num);
			printf ("the number of tail set bits are %d\n", res);
			break;
		case 15:
			printf ("enter number\n");
			scanf ("%x", &num);
			res = count_tail_clear_bits (num);
			printf ("the number of tail clear bits are %d\n", res);
			break;
		case 16:
			printf ("enter sourse and destination number and no of bits, sourse bit\n    "); 
			scanf ("%x%x%d%d", &snum, &dnum, &n, &s);
			res = setbits_rightmost (snum, dnum, n, s);
			printf ("after copying the dnum is %x\n", res);
			break;
		case 17:
			printf ("enter number and no of bits, position\n");
			scanf ("%x%d%d", &num, &n, &posn);
			res = invert_bits (num, n, posn);
			printf ("after inverting the num is %x\n", res);
			break;
		case 18:
			printf ("enter numbers, num and source and destination bits and position     and no of bits \n");
			scanf ("%d%d%x%d%d%d", &num1, &num2, &num, &s, &d, &posn);
			max_min_nums (num1, num2);
			set_bit (num, posn);
			clear_rightmost_set (num);
			set_rightmost_clear (num);
			clear_leftmost_set (num);
			set_leftmost_clear (num);
			set_range_bits (num, s, d);
			clear_range_bits (num, s, d);
			toggle_range_bits (num, s, d);
			getbits_leftadj (num, n, posn);
			break;
		default: printf ("entererd unknown question number\n");
			break;
	}
	return 0;
}
