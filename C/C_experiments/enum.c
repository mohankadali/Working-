#include <stdio.h>
#define MAX 10
void fun(int x,int y)
{
    printf("%d",x);
    printf("%d",y);
}
main () 
{
    fun(MAX,MAX-1);
}
