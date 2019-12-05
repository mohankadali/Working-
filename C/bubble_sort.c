#include <stdio.h>
int main()
{

	int a[9] = {1,7,8,2,9,3,4,6,5};
	int temp,i,j,ele;
	ele = sizeof(a)/sizeof(a[0]);

	for(i=0;i<ele-1;i++)
	{
		for(j=0;j<ele-i-1;j++)
		{
			if(a[j] < a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);





	return 0;
}
