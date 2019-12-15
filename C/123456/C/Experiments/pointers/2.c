#include<stdio.h> 
main()
{
    char a[10]={};
printf("%p   ",a);
printf("%d   ",sizeof(a));
printf("%p   ",a+1);
printf("%p   ",&a+1);
}
