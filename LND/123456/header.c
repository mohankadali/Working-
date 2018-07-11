#include<stdio.h> 

#define x(x) #x

int main()
{
    char a[10]=x(TEL);
    printf("%s\n",a);
}
