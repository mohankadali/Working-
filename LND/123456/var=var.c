#include<stdio.h> 
int var =10;
int main()
{

    int var = var;

    printf("%p\n",&var);
    printf("%d\n",var);

    return 0;
}
