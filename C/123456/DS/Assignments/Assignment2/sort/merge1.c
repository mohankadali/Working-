#include<stdio.h> 
void merge(int a[],int n)
{
    int mid = n/2;
    int left [mid];
    int right[n-mid];
    int i;
    for(i=0;i<mid-1;i++)
    {
        left[i]=a[i];
    }
    for(i=mid-1;i < n-1;i++)
    {
        right[i-mid]=a[i];
    }
    merge(left,mid);
    merge(right,n-mid);
} 
main()
{
    int a[10]={1,54,2,6,8,3,56,32,11,43};
    int i;
    merge(a,sizeof(a));
    for(i=0;i<10;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");
}
