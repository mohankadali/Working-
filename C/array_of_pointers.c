#include <stdio.h>
int main()
{

int a[5]= {1,2,3,4,5};
int *p[5];

p[1] = &a[1];

printf("%d\n",*p[1]);

return 0;
}
