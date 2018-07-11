#include <stdio.h>

int main(void)
{
   int i = 3;
   int j;

   j = sizeof(++i + ++i);

   printf("i=%d j=%d\n", i, j);

   return 0;
}

