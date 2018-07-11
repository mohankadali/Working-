#include <stdio.h>
#include <stdlib.h>

main()
{
	int num = 0xa0303030, pos = 4, mask = ((sizeof(unsigned) * 8));
	num = (num << pos)|(num >> (mask - pos));
	printf("%08X \n", num);

	return 0;
}
