#include <stdio.h>
int main()
{
        int num = 157,temp,rem;
        int sum =0;
        while(num)
        {
                rem = num%10;
                sum = sum +rem*rem*rem;
                num = num/10;
        }
        if(temp == sum)
                printf("%d is armstrong number...\n",sum);
        return 0;
}
