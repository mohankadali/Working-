#include <stdio.h>

int main()

{
	void *p;
	int a[4] = {1, 2, 3, 8};
	int *ptr;
	int n;

	int *tmp;

	p = &a[3];
	ptr = &a[1];

	tmp = p;
	n = tmp - ptr;
	n = n + 010;

	printf("%d\n", n);
}
