#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int size, i, j, ele;
	int *p;
	//  int arr[size];
	//  p = arr;
	printf ("enter the size\n");
	fgets ((char*)&size, 3, stdin);
	size = atoi ((char*)&size);
	
	p = (int*)malloc (size * sizeof (int));
	
	printf ("enter elements\n");
										/* entering the data */		
	for(i = 0; i < size; i++) {
		fgets ((char*)(p + i), 4, stdin);
		*(p + i) = atoi ((char*)(p + i));
	}

										/* sorting the data */
	for(i = size-1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (*(p + i) < *(p + j)) {
				ele = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = ele;
			}
		}
	}
										/* printing rhe elements */	
	for (i = 0; i < size; i++)
		printf ("%d\t", *(p+i));
	printf("\n");
	return 0;
}
