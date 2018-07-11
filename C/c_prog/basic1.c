#include<stdio.h>
int main()
{

const int x = 10;
    int *p = &x;
    *p = 90;
    printf("%d\n",x);
return 0;
}
