#include<stdio.h> 
int main(void)
{
    char a[100] = {[99] = 10};

//    printf("%d\n",a[99]);

printf("%d ",~0);
printf("%d ",~0 << 2);
printf("%d ",~(~0 << 2));

    a[99] = a[99] & ~((~(~0 << 4))<<0);
    printf("%d\n",a[99]);

    return 0;
}
