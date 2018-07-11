#include <stdio.h>
void signed_one(int);
void unsigned_one(int);
void main()
{
    printf("\nrange of char");
    signed_one(sizeof(int)*8);
    printf("\nrange of unsigned char");
    unsigned_one(sizeof(unsigned int)*8);
}
void signed_one(int count)
{
    int min, max;
    int pro = 1;
    while (count != 1)
    {
        pro = pro << 1;
        count--;
    }
    min = ~pro;
    min = min + 1;
    max = pro - 1;
    printf("\n%d to %d", min, max);
}    
void unsigned_one(int count)
{
    unsigned int min, max, pro = 1;
    while (count != 0)
    {
        pro = pro << 1;
        count--;
    }
    min = 0;
    max = pro - 1;
    printf("\n%u to %u", min, max);
}
