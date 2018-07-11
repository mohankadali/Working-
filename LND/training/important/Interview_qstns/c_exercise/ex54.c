#include<stdio.h>
const int b = 20;
const int c;
int main()
{
   int *ptr;
   ptr = &c;
   *ptr = 10;
   printf("%d",c);
    return 0;
}
