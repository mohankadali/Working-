#include<stdio.h>
int main()
{
        char *ptr="Hello"
                "\0"
                "world";
        printf("%s",ptr);
}
