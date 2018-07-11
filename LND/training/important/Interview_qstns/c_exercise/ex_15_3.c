#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);

	/* printf("%d\n", a&~(3)); */
	/* printf("%d\n", (a >> 2) << 2); */
	 printf("%d\n", a - (a & 3));
}
