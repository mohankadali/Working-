#include<stdio.h> 
main()
{
    float f=3.14;
    int i,*p=(int*)&f;
    for(i=31;i>=0;i--)
        printf("%d",*p>>i&1);
}
