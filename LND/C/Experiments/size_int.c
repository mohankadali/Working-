#include<stdio.h>
int main(void)
{

	int size_int,min=1,max=0,size,i;
	size_int=sizeof(int);
	size=8*size_int-1;
	for(i=size;i>0;i--)
	{
		min=min*2;
	}
	max=min-1;
	printf("size of int is  %d\n",size_int);
	printf("range is \n -%d to %d\n",min,max);
	return 0;
}
