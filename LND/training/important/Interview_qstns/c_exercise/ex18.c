#include <stdio.h>

int main(void)
{
   struct node
   {
      int a;
      int b;
      int c;
   };
   struct node s = { 3, 5, 6 };
   struct node *pt = &s;

   printf("%d\n", *(int*)pt);

   return 0;
}

