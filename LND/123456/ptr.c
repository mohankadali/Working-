#include<stdio.h> 
int main(void)
{
    char *ptr = "hello";

    printf("%p\n",ptr);
    ptr++;
    printf("%s\n",++ptr);
    return 0;
}
