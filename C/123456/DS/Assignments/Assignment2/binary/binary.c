#include <stdio.h> 
#define MAX 9 
int BINARY (int *a, int num)
{
    int i;
    int  last = MAX - 1;
    int  first = 0 ;
    int mid = (first + last) / 2;
    for (; first <= last; )
    {
        mid = (first + last) / 2;
        if (num < a[mid])
        {
            first = 0;
            last = mid - 1;

        }else if (num > a[mid])
        {
            first = mid + 1;
            last = MAX - 1;
        }
        if (a[mid] == num)
            return 1;
//        else
  //          return 0;        
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
    result=BINARY(a,num);
    if(result)
        printf("yes\n");
    else
        printf("no\n");
}
