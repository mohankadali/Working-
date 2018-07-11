#include <stdio.h>
#include <stdlib.h>
int quick_sort (int *, int, int);
int main (void)
{
	int size, i, j,  temp, min = 0;
	int pivot=0, low=0, high;
	int *p;
	//  int arr[size];
	//  p = arr;
	printf ("enter the size\n");
	fgets ((char*)&size, 4, stdin);
	size = atoi ((char*)&size);
	p = (int*)malloc (size * sizeof (int));
	high = size-1;
	printf ("enter elements\n");
	/* entering the data */		
	for (i = 0; i < size; i++) {
		fgets ((char*)(p + i), sizeof(int), stdin);
		*(p + i) = atoi ((char*)(p + i));

	}
	for (i = 0; i < size; i++)
		printf ("%d\t", *(p+i));
	low=0,high=size-1;
	quick_sort (p, low, high);
/*	pivot = *(p+low);
	i = low + 1;
	j = high;

	quick_sort(int *p, low, high);
	while (low <= high) {
		
	i = low + 1;
	j = high;
	pivot = *(p+low);
		while (i <= j) {

			while (*(p + i) <= pivot)
				++i;
			while (*(p + j) > pivot)
				--j;
			if (i < j) {
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
				++i;
				--j;
			}
			else
				++i;
	}
	if (low < j) { 
	printf ("\nswaping\n");	
	temp = *(p + j);
	*(p + j) = *(p + low);
	*(p + low) = temp;
	low = low+1;
	}
	

	}
 printing rhe elements */	
	for (i = 0; i < size; i++)
		printf ("%d\t", *(p+i));
	printf("\n");
return 0;
}

