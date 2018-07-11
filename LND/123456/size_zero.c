#include<stdio.h> 
int main()
{
    int a[0];

    printf("%d\n",sizeof(a));
    printf("%p\n",&a);
    printf("%p\n",a);
    return 0;
}
