#include"header.h"
int main (void)
{
    int s,d;
    int a,b;
    printf("enter the numbers...\n");
    scanf("%d%d",&a,&b);
    s=sum(a,b);
    d=diff(a,b);
    printf("sum of the numbers=%d\n",s);
    printf("diff of the numbers=%d\n",d);
    return 0;
}
