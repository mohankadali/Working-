#include<stdio.h>
int main()
{
    char str[]="hello";
    char str1[] ="world";
    char *p,*q;
    p=&str;
    q=&str1;
    while(*p++ = *str1++ );
//    while(*str1++ = *q++);
    printf("%s", str1);
    return 0;
}
