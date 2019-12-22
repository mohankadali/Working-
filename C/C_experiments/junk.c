#include<stdio.h>
#define NUM 10

#ifdef NUM
void main()
{
    printf("MAX number is : %d",NUM);
}
#endif

#ifndef NUM

void main()
{
    printf("MAX number is : %d",123);
}
#endif
