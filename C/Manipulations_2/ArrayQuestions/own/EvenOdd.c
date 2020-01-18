#include <stdio.h>
int main()
{
        int num = 8;

        (num & 1 && printf("odd") || printf("Even"));

        return 0;
}
