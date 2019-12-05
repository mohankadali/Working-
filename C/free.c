#include <stdio.h>
#include <stdlib.h>

int main()
{

int *p = NULL;
p = malloc(100);
printf("%d\n",p);
free(p);
printf("%d\n",p);
free(p);
printf("%d\n",p);
return 0;
}
