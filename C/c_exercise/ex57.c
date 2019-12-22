#include <stdio.h>
int main()
{
	int a[][2] = {{1, 2}, {2, 3}, {4, 5}}; 
	printf("\n &a ->%u", &a);
	printf("\n &a+1 ->%u", &a + 1);
	printf("\n a+1 ->%u", a + 1);
	printf("\n *a+1 ->%u", *a + 1);
	printf("\n **a+1 ->%u", **a + 1);
	printf("\n\n"); 
	return 0;
}
