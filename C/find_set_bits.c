#include<stdio.h> 

int numones(int n) 
{ 
    if (n==0)
        return 0;
    else if( n == 1)
        return 1;
    else
        return numones (n/2) + numones (n%2);
}
int main()
{

    int num =  numones(10);
    printf("set bits = %d\n",num);
}
