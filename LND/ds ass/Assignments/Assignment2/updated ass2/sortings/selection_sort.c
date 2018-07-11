#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int size, i, j,  temp, min = 0;
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
										/* sorting the data */
	for (i = 0; i < size; i++) {
		min = i;
		
		for (j = i + 1; j < size; j++) {
					
			while (*(p + min) > *(p + j)) {
				min = j;
				j = j + 1;
			}
		}
		if (*(p+i) > *(p+min)){
		printf ("\nswaping\n");	
		temp = *(p + i);
		*(p + i) = *(p + min);
		*(p + min) = temp;
		}
		}
			

		
									/* printing rhe elements */	
	if(size%2==0) {
		for (i = 1; i <= size; i++)
		printf ("%d\t", *(p+i));
	printf("\n");
	}
	else
	{
		for (i = 0; i < size; i++)
		printf ("%d\t", *(p+i));
		printf("\n");
	}
	return 0;
}

