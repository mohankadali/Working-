#include <stdio.h>
int main()
{
        int a[] = {1,2,3,4,5,6};
        int ele = sizeof(a)/sizeof(a[0]);
        int num  = 10;
        int pos = 3;
        int i;
#if 0
        // insertion
        for (i = ele; i>pos; i--)
        {
                a[i+1] = a[i];
        }
        a[i+1] = a[i];
        a[i] = num;
        for(i=0;i<ele+1;i++){
                printf("%d  ",a[i]);
        }
#endif 
        //deletion
        for(i=pos;i<ele;i++)
        {
                a[i] = a[i+1];
        }
        for(i=0;i<ele-1;i++){
                printf("%d  ",a[i]);
        }

        return 0;
}
