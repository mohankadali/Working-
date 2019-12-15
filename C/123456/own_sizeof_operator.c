#include<stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
int main()
{
    char num = 0;
    printf("%d\n",my_sizeof('A'));
    return 0;

}
