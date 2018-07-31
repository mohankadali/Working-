#include <stdio.h>
int main()
{
        int a[] = {1,2,3,4,5};
        int i;
        int j= sizeof(a)/sizeof(a[0]);
        int temp;
        for (i=0;i<j+1;i++,j--)
        {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
        }
        for (i = 0 ;i<5; i++)
                printf("%d   ",a[i]);
        return 0;
}
