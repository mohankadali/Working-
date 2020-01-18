#include <stdio.h>
int fun(int num)
{
        if (num == 0)
        {
                return 0;
        }
        else
        {
                printf("%d ",num);
                fun(num-1);
        }
}

int main()
{
int num = 10;

fun(num);

return 0;
}
