#include <stdio.h>
int main()
{
	int i;
	printf("%s \n", __TIME__);
	sleep(5);
	for (i = 0; i < 100; i++);
	printf("%s \n", __TIME__);
	return 0;
}
