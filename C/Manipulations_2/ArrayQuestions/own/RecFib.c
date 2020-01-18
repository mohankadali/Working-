#include <stdio.h>
int fib(num)
{
        if (num == 1 || num ==0)
                return 1;
        else
                return fib(num-1)+fib(num-2);
}


int main()
{
        int i;
        for(i=0;i<10;i++)
        {
                printf("%d ",fib(i));
        }
        return 0;
}
