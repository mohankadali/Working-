#include <stdarg.h>
#include <stdio.h>

int ripple(int n, ...)
{
   int i, j, k;
   va_list p;

   k = 0;
   j = 1;
   va_start(p, n);

   for (; j < n; ++j)
   {
      i = va_arg(p, int);
      printf("arg %d:%d \n", j, i);
      for (; i; i &= i - 1)
         ++k;
   }
   va_end(p);
   return k;
}

int main(void)
{
   printf("%d\n", ripple(3, 5, 7));
   /* printf("%d\n", ripple(6, "ss", 7, 8)); */
   return 0;
}

