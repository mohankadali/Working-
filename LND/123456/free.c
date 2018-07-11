#include<stdio.h> 
int main(void)
{
//main();
    int x=10;

    printf("%p\n",&x);
    free((int*)&x);
    printf("%d\n",x);

    return 0;
}

