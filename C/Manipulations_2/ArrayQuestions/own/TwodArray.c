#include <stdio.h>
/*
void fun( int (**b)[3]  )
{
        int i,j;
        for (i =0;i<3;i++)
        {
                for(j=0;j<3;j++)
                printf("%d ",b[i][j]);
                }
                }
 */
int main()
{
        int a[][4] = {2,3,4,5,6,7,8,9};
        int (*b)[] = a ;
//        int **c = a;
        int i,j;
        for (i =0;i<2;i++)
        {
                for(j=0;j<4;j++)
                        printf("%d ",*(*(b+i)+j));
        }

        return 0;
}
