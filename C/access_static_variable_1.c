#include<stdio.h> 
int main(void)
{
    extern int *q;
    printf("%d\n",*q);
    return 0;

}
