#include<stdio.h>
struct A
{
    double d;
};
struct bitfields
{
    int i;
    int a:16;
    float j;
    int b:16;
    struct A k;
    unsigned int c:7;
};

int main()
{
    printf(" %d ",sizeof(struct bitfields));
}

