#include<stdio.h> 
int main(void)
{
    int c;
    int a =10;
    int b=20;
    c = ((((a ^= b) ^ b) & b ) << 1 ); 
        printf("%d\n",c);
    return 0;
}

