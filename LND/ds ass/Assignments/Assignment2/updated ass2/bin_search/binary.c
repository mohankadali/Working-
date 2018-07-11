#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	static int size, i, ele, low, high, mid;
	int *p;
	printf ("enter the size\n");
	fgets ((char*)&size,3,stdin);
	size = atoi ((char*)&size);
	p = (int*)malloc (size*sizeof (int));
	printf ("enter elements\n");
	
	for (i = 0; i < size; i++) {
		fgets ((char*)(p+i), 5, stdin);
		*(p+i) = atoi ((char*)(p+i));
	}
	low = 0;
	high = size - 1;
	mid = (low + high) / 2;
	printf ("enter the element\n");
	fgets ((char*)&ele, 5, stdin);
	ele = atoi ((char*)&ele);
	while (low <= high) {
	if (ele == *(p + mid)) {
		printf("element found\nelement is at position %d\n", mid+1);
		exit (0);
	}
	else if (ele < *(p+mid)) {
		high = mid - 1;
		mid = (low + high) / 2;
	}
	else if (ele > *(p+mid)) {
		low = mid + 1;
		high = size - 1;
		mid = (low + high) / 2;
	}

	}

	if(ele != *(p+mid))
		printf("element not found\n");
}
		
	

