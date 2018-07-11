#include<stdio.h>
main()
{
    int num=0x1234567;
    int i;
    for(i=31;i>=0;i--)
    {
        printf("%d",num>>i&1);
    }
printf("\n");
}
