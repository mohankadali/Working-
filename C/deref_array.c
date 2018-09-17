#include <stdio.h>
int main()
{

 int a[] = {1,2,3,4,5,6,7,8};

printf("%d\n",*(a+0));
 
int *p = a+1;

printf("%d\n",*p);

return 0;
}
