#include<stdio.h> 
int main(void)
{
    int i;
    int sum = 0,sum1 = 0;
    for( i = 0 ;i<=10 ;i = i+5  )
    {
        if(i%5 == 0)
            sum = sum +i;
    }
    for( i = 0 ;i<=10 ;i = i+3  )
    {
        if(i%3 == 0)
            sum = sum +i;
    }
    printf("sum = %d\n",sum);
    for(i=0;i<=10;i++)
    {
        if( i%5 == 0 || i%3 == 0 )
            sum1 = sum1+i;
    }
    printf("sum1 = %d\n",sum1);
    return 0;
}
