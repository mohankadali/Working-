#include<stdio.h> 
void fun(int a) 
{
    printf("%d\n",a);
}
int main(void)
{
    void (*fun_ptr)() = fun ;

    (fun_ptr)(10);

    return 0;
}
