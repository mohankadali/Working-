#include <stdio.h>
#include <stdlib.h>
int main()
{

int *p = NULL;
printf("before size %p\n",p);
free(p);
p = (int *)malloc(100);
printf("after size %p\n",p);
free(p);
printf("after size %p\n",p);
return 0;
}
