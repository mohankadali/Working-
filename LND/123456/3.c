#include<stdio.h> 
int main(void)
{
    int a = 0xabcdef11;
    char  *p;

    p= &a;

    printf("%x\n",*p);
    return 0;
}
