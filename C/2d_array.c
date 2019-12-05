#include <stdio.h>

int main()
{

	int **ptr = NULL;
	int j=0,i=0,r=2,c=3;

	ptr = (int**) malloc(r * sizeof(int));

	for(i=0;i<r;i++)
	{
		ptr[i] = (int*)malloc(c * sizeof(int));
	}
	ptr[1][1] = 10; 

	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("arra =  %d\n",ptr[i][j]);
	}

	return 0;
}
