#include <stdio.h>
int main()
{
	int a[] = {1,8,2,9,3,5,6,7,4};
	int ele = sizeof(a)/sizeof(a[0]);
	int i,j,temp;

	for(i=0;i<ele;i++)
	{
		for(j=i;j<ele-1;j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

	}
	for(i=0;i<ele-1;i++)
		printf("%d ",a[i]);

	return 0;
}
