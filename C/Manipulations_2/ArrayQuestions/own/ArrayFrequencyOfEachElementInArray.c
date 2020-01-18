#include <stdio.h>
void freq(int p[],int n)
{
        int q[200]={};
        int i;
        for (i=0;i<7;i++)
        {
                if( q[p[i]] == 1)
                {
                        printf("%d  \n",p[i]);
                }
                else
                q[p[i]] = 1;
        }
}
int main()
{
        int a[] = {1,1,2,2,3,4,4};
        freq(a,sizeof(a)/sizeof(a[0]));
        return 0;
}
