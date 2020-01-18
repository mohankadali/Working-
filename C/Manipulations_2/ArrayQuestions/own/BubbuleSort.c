#include <stdio.h>
int main()
{
        int a[]={1,2,6,5,3,4,7,9,8};
        int ele = sizeof(a)/sizeof(a[0]);
        int i,j,temp;
        for (i =0;i<ele-1;i++)
        {
                for(j=0;j<ele-i-1;j++)
                {
                        if (a[j] < a[j+1])
                        {
                                temp = a[j];
                                a[j] = a[j+1];
                                a[j+1] = temp;
                        }
                }
        }
        for(i=0;i<ele;i++)
                printf("%d ",a[i]);
        printf("\n");
        return 0;
}
