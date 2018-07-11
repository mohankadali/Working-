#include<stdio.h> 
#include<stdlib.h>
#define MAX 10
int SEARCH(int a[],int num)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(num==a[i])
            return 1;
    }
    return 0;
}
main()
{
    int *a;
    a=malloc(sizeof(int)*MAX);
    int result,i,num;
    printf("enter the array elemetns..\n");
    for(i=0;i<MAX;i++)
        scanf("%d",&a[i]);
    printf("enter the number to search...\n");
    scanf("%d",&num);
    result=SEARCH(a,num);
    if(result)
        printf("yes\n");
    else
        printf("no\n");
}
