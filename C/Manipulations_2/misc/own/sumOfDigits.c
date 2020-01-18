#include <stdio.h>
int main()
{
        int num = 12345,temp,rem;
        int sum =0;
        while(num)
        {
                while(num)
                {
                        rem = num%10;
                        sum = sum +rem;
                        num = num/10;
                }
                if(sum < 9)
                        break;
                else

                {
                        num = sum ;
                        sum = 0;
                }
        }
        printf("%d\n",sum);
        return 0;
}
