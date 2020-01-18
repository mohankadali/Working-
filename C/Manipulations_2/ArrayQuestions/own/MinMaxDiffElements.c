#include <stdio.h>
int main()
{
        int a[] = {1,2,3,4,5,6,7,8};
        int min = a[0];
        int max = a[0];
        int i;
        for(i=0;i<8;i++)
        {
                if(min > a[i])
                {
                        min = a[i];
                }
                if(max < a[i])
                {
                        max = a[i];
                }
        }
        printf("%d  %d\n",min,max);
        return 0;
}
