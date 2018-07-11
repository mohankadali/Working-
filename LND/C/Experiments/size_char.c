#include<stdio.h>
int main(void)
{

	int size_char,min=1,max=0,size,i;
	size_char=sizeof(char);
	size=8*size_char-1;
	for(i=size;i>0;i--)
	{
		min=min*2;
	}
	max=min-1;
	printf("size of char is  %d\n",size_char);
	printf("range is \n -%d to %d\n",min,max);
	return 0;
}
