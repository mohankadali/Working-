#include <stdio.h>
int main()
{

int a[500];

char *c = (char*) a;

printf("%d\n",c[100]);
return 0;
}
