#include <stdio.h>
#include <stdlib.h>

int quick_sort (int *p, int low, int high) 
{
	int i, j, pivot, temp;

	i = low + 1;
	j = high;

	if (low > high) 
		return;

	pivot = p[low];
	printf ("pivot   is %d\n", pivot);

	while (i <= j) {
		printf("low is %d\n",low);

		while (p[i] < pivot)
			++i;

		while (p[j] > pivot)
			--j;

		if (i > j) 
			break;
		
		if(i>j)
			break;

		temp = p[j];
		p[j] = p[i];
		p[i] = temp;
		++i;
		--j;

	}
	if (low < j) {
		temp = p[j];
		p[j] = p[low];
		p[low] = temp;
		low = low + 1;
	}
	
	quick_sort (p, low, j - 1 );
	quick_sort (p, j + 1, high);
}
