#include<stdio.h> 
#define  MAX  (-1u)>>1 
int main(void)
{

    printf("%d  \n",MAX);
    int i;
    for(i=31;i>=0;i--)
    {
        printf("%d",(MAX)>>i&1);
    }
    return 0;
}
