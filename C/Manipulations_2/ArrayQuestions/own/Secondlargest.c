#include <stdio.h>
int main()
{
        int a[] = {1,2,3,4,5,6,7};

        int first,second,i;
        first = second = a[0];
        for(i=0;i<7;i++)
        {
                if (first < a[i])
                {
                        second = first;
                        first = a[i];
                }
               else if(second < a[i])
                        second = a[i];
        }

        printf("%d \n",first);
        printf("%d \n",second);
        return 0;
}
