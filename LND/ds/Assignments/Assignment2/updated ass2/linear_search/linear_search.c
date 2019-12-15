#include <stdio.h>
#include <stdlib.h>
int main(void)
{                                                                          
	int size, i, ele;
	int *p;
//	int arr[size];
//	p = arr;
	printf ("enter the size\n"); 
	fgets ((char*)&size,4,stdin);                  
	size = atoi ((char*)&size);
	p = (int*)malloc (size*sizeof (int));
	printf ("enter elements\n");
	for(i = 0; i < size; i++) {
		fgets ((char*)(p+i), 4, stdin);                  
		*(p+i) = atoi ((char*)(p+i));
	}
	printf("enter the element\n");
	fgets ((char*)&ele,4,stdin);                  
	ele = atoi ((char*)&ele);
	for(i=0;i<size;i++) {
		if (*(p+i)==ele)
			printf("element is found\n element is at index %d\n",i);
	}
return 0;
}
