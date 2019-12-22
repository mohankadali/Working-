#include        <stdio.h>
struct value
{
        char bit1;
        long long bit4;
        char bit2;
};
int main()
{
        struct value bit;
        printf("%lu %lu \n", sizeof(bit), sizeof(long double));
        return 0;
}

