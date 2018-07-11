#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int size, i, j,  temp, min;
	int *p;
	//  int arr[size];
	//  p = arr;
	printf ("enter the size\n");
	fgets ((char*)&size, 4, stdin);
	size = atoi ((char*)&size);
	p = (int*)malloc (size * sizeof (int));

	printf ("enter elements\n");
	/* entering the data */		
	for (i = 0; i < size; i++) {
		fgets ((char*)(p + i), sizeof(int), stdin);
		*(p + i) = atoi ((char*)(p + i));
	}
	min = 0;
	for (i = 0; i < size; i++)

		printf ("%d\t", *(p+i));
	printf("\n");
	/* sorting the data */
	for (i = 1; i < size; i++) {

		for (j = 0; j < i; j++) {
			if (*(p+i) < *(p+j)){

				printf ("\nswaping\n");	
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}

	}


	/* printing rhe elements */	
	for (i = 0; i < size; i++)
		printf ("%d\t", *(p+i));
	printf("\n");
	return 0;
}

