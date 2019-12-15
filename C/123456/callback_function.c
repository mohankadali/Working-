#include<stdio.h> 
#if 0
void A()
{
        printf("hi \n");
}
void B(void (*fun)())
{
        (*fun)();
}
int main()
{
        void (*fun)()  = &A;
        B(fun);
        return 0;
}
#endif
#if 0
int  new (int (*new_funptr) (int ,int ) )
{
    printf("in new...\n");

    int s = 100 + (*new_funptr)(1,2);
    return s;
}

int  my_callback( int a ,int b )
{
    printf("my own call back...\n");
    return a+b;
}

int main(void)
{


    int sum1 = new ( my_callback ) ;

    printf("sum1= %d\n",sum1);
    return 0;
}
#endif
#if 0
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
#endif 
