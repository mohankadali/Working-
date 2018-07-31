#include <stdio.h>
void fun(int *p, int n)
{
        int i;

        for (i=0;i<n;i++)
        {
                printf("%d  ",p[i]);
        }

}
int main()
{
        int a[] = {1,2,3,3,4,5,6};

        fun(a,sizeof(a)/sizeof(a[0]));

        return 0;
}
