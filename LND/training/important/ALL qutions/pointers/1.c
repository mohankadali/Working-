#include <stdio.h>
#include <stdlib.h>
int main()
{
        int *p[10];
        int *(*q)[10];
        printf("%lu %lu\n", sizeof(int), sizeof(int *));
        printf("%lu %lu\n", sizeof p, sizeof p[0]);
        printf("%lu %lu\n", sizeof q, sizeof *q);
        return 0;
}
