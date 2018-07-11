#include	<stdio.h>
#include	<stdlib.h>
struct header {
	char src[6];
	char dest[6];
	char recv[6];
};

int main()
{
	struct header dev_a, dev_b = {0};
	int i;

	for (i = 0;i < 6;i++) {
		dev_a.src[i] = dev_a.dest[i] = dev_a.recv[i] = i;
	}

	memcpy(&dev_b.dest, &dev_a.dest, 8);

	for (i = 0;i < 6;i++) {
		printf("%d %d %d\n", dev_b.src[i], dev_b.dest[i], dev_b.recv[i]);
	}
	return 0;
}
