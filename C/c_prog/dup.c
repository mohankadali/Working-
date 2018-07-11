#include<stdio.h>
void dup(int a[],int num)
{
    int *count = (int*) malloc(100);

    int i;
    for(i=0;i<num;i++)
    {
        if(count[a[i]] == 1 )
            printf("%d ",a[i]);
        else
            count[a[i]]++;
    }
}
int main(void)
{

    int a[] = {3,5,2,5,3,6,4,5,6,7,3,5,4,3};
    int ele = sizeof(a) / sizeof(a[0]);
    dup(a,ele);
    return 0;
}
