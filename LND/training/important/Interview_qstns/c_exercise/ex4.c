#include	<stdio.h>
#include	<stdlib.h>
struct header {
	char src[6];
	char dest[6];
	char recv[6];
};
void print_header(void *ptr)
{
	/* printf("%d", ((struct header *)ptr)->src[4]); */
	printf("%d", ptr->src[4]);
}

int main()
{
	struct header dev_a, dev_b = {0};
	int i;

	for (i = 0;i < 6;i++) {
		dev_a.src[i] = dev_a.dest[i] = dev_a.recv[i] = i;
	}

	print_header(&dev_a);
	return 0;
}
