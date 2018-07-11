#include<stdio.h> 
int add()
{
    return 10+20 ;
}
int sub()
{
    return 20-10 ;
}

void my_fun( int (*fun1)() ,int (*fun2)() )
{

    int x = (*fun2)() +   (*fun1)();

    printf("%d\n",x);
}
int main(void)
{

    int (*fun)() = add  ;
    int (*fun1)() = sub  ;


    my_fun(  fun   ,fun1 );

    return 0;
}
