#include <stdio.h>
int main()
{
        int a[] = {1,1,1,2,2,4,51,2,2};
        int ele = sizeof(a)/sizeof(a[0]);
        int i,j;
        int b[200]= {};

        for (i = 0;i<ele ;i++)
        {
                if( b[a[i]] == 0)
                {
                        printf("%d ",a[i]);
                }
                if (b[a[i]]==1) 
                {
                        for (j = i;j<ele;j++)
                        {
                                a[j] = a[j+1];        
                        }
                        ele--;
                        i--;
                }
                b[a[i]] = 1;
        }
        printf("final array...\n");
        for(i= 0;i<ele;i++)
        {
                printf("%d ",a[i]);
        }
}
