#include <stdio.h>
#if 0
int main()
{
int num = 10;
int i;

for(i =0;i<=10;i++)
{
        printf("%d X %d = %d\n",i,num,i*num);
}
return 0;
}

#endif

#if 1
int rec_mul(int num)
{
        if(num == 0)
                return 1;
        else
        {
                printf("%d\n",num);
                return rec_mul(num-1) + num;

        }
}
int main()
{
                        int num = 10;

                        int res= rec_mul(num);
                        printf("%d\n",res);       
                        return 0;
                }
#endif
