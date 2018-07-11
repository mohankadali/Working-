#include<stdio.h>
#define base 10
int main(void)
{
	int num, num1;			/*storing a number to check palindrome*/
    int rev=0;			/*for storing reverced value*/
    int res; 
	int count=0;
	int rem;
    int	pos;
	printf("enter number\n");
	scanf("%d", &num);
	num1=num;
	while(num) {
		rem = num%base;
		num = num/base;
		rev = (rev*base)+rem;
	}
	res = (num1)^(rev);
	if(res==0)
		printf("given number is a palindrome\n");
	else
		printf("not a palindrome\n");
return 0;
}
