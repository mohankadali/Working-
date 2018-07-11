#include <stdio.h>

#define SIZEOF(x) SIZEOF1(x)
#define SIZEOF1(y) ( __typeof__(y) tmp; (((char *)(&tmp + 1)) -((char*)(&tmp));)

int main()
{
printf("%d\n",SIZEOF(int));

return 0;
}
