#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int size, size1, size2, i=0, j=0, k=0;
	int *p, *q, *r;

	printf ("enter the size of first array\n");
	fgets ((char*)&size1, sizeof(int), stdin);
	size1 = atoi ((char*)&size1);
	p = (int*)malloc (size1 * sizeof (int));

	printf ("enter elements of array1\n");
	
	/* entering the data of first array */		
	for (i = 0; i < size1; i++) {
		fgets ((char*)(p + i), sizeof(int), stdin);
		*(p + i) = atoi ((char*)(p + i));
	}
	printf ("enter the size of second array\n");
	fgets ((char*)&size2, sizeof(int), stdin);
	size2 = atoi ((char*)&size2);
	q = (int*)malloc (size2 * sizeof (int));

	printf ("enter elements of array2\n");

	/* entering the data of second array */		
	for (i = 0; i < size2; i++) {
		fgets ((char*)(q + i), sizeof(int), stdin);
		*(q + i) = atoi ((char*)(q + i));
	}

	size = size1 + size2;
	r = (int*)malloc (size * sizeof (int));
	
	/* sorting the data */
	while (k != size) {
		
		while (i != size1) {
			
			if (j == size2){
				*(r + k) = *(p + i);
				i = i + 1;
				k = k + 1;
			}

			else if (*(p + i) <= *(q + j)){
				*(r + k) = *(p + i);
				i = i + 1;
				k = k + 1;
			}
			
			else 
				break;

		}
		
		while (j != size2) {
			
			if (i == size1) {
				*(r + k) = *(q + j);
				j = j + 1;
				k = k + 1;
			}

			else if (*(p + i) > *(q + j)) {
				*(r + k) = *(q + j);
				j = j + 1;
				k = k + 1;
			} 
			
			else 
				break;
		}

	}

	/* printing rhe elements */	
	for (k = 0; k < size; k++)
		printf ("%d\t", *(r+k));
	
	printf("\n");
	return 0;
}

