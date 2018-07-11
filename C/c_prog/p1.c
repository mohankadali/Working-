#include <stdio.h>
//#include <assert.h>
//#include <ctype.h>

long long int my_atoi(const char *c)
{
    long long int value = 0;
    int sign = 1;
    if( *c == '+' || *c == '-' )
    {
        if( *c == '-' ) sign = -1;
        c++;
    }
    while (isdigit(*c))
    {
        value *= 10;
        value += (int) (*c-'0');
        c++;
    }
    return (value * sign);
}

int main(void)
{
    printf("%d", my_atoi("5"));
    return 0;
}
