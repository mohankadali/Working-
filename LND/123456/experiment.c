#include<stdio.h> 
int main() 
{

    int  (*ptr)[5] ;
    int a[][5]  = {1,2,3,4,5,3};

    ptr = a;

    printf("%p\n",ptr);
    printf("%p\n",a);
    printf("%p\n",a[1]);
    printf("%d\n",ptr[1][2]);

    return 0;
} 
