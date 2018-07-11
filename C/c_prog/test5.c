#include<stdio.h>
const int b = 20;
const int c;
int main()
{
    int *ptr;
 //   ptr = &c;
    ptr = &b;
    *ptr = 10;
   // printf("%d",c);
    printf("%d",b);
    return 0;
}
