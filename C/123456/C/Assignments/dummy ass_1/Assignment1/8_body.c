#include<stdio.h> 
int cnt_trailing_cleared_bits ( int num )
{
    int i,c=0;
    for(i=0;i<=31;i++)
    {
        if((num>>i&1)==0)
        {
            c++;
        }
        else
        {
            return c;
        }
    }
}
int cnt_trailing_set_bits (int num)
{
    int i,c=0;
    for(i=0;i<=31;i++)
    {
        if((num>>i&1)==1)
        {
            c++;
        }
        else
        {
            return c;
        }
    }
}
int cnt_leading_set_bits(int num)
{
    int i,c=0;
    for(i=31;i>=0;i--)
    {
        if((num>>i&1)==1)
        {
            c++;
        }
        else
        {
            return c;
        }
    }
}
int cnt_leading_cleared_bits(int num)
{
    int i,c=0;
    for(i=3;i>=0;i--)
    {
        if((num>>i&1)==0)
        {
            c++;
        }
        else
        { 
            return c;
        }
    }
}
int leading()
{
    int num,result,option;
    printf("enter the option 1)cnt_leading_set_bits\n2)cnt_leading_cleared_bits\n3)cnt_trailing_cleared_bits\n4)cnt_trailing_set_bits ...\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            printf("enter the number...\n");
            scanf("%d",&num);
            result=cnt_leading_set_bits (num);
            break;
        case 2:
            printf("enter the number...\n");
            scanf("%d",&num);
            result=cnt_leading_cleared_bits (num);
            break;
        case 3:
            printf("enter the number...\n");
            scanf("%d",&num);
            result=cnt_trailing_cleared_bits (num);
            break;
        case 4:
            printf("enter the number...\n");
            scanf("%d",&num);
            result=cnt_trailing_set_bits (num);
            break;
        default:
            break;
    }
    return result;
}
