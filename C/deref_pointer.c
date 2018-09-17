#include <stdio.h>
int main()
{

int a[] = {1,2,3,4,5,6,7,8};

int *p = a;

printf("%d\n",*(p+0));

p++;

printf("%d\n",*(p));

return 0;
}
