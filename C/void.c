#include <stdio.h>
int main()
{

char *p;
int a = 0x1234;

p =(char*) &a;

printf("%d \n",*p);

return 0;
}
