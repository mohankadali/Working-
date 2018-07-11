#include<stdio.h> 

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
