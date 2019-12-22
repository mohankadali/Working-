#include    <stdio.h>
int main()
{
    int p = 2;
    int i;
    p = -p;
printf("%d\n",p);
    for(i=31;i>=0;i--)
        printf("%d",p>>i&1);

    
    return  0;
}
