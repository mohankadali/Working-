#include<stdio.h> 
int rec(int num,int num1) 
{

    if(num1 == num+1)
        return 0;

    printf("%d\n",num1);
    rec(num,num1+1);
}
int main(void)
{
    int num= 5;
    int num1 =1;
    rec(num,num1);
    return 0;
}
