#include<stdio.h>
int atoi(char *s)
{
    int value = 0;
    int i;

    for(i=0;s[i];i++)
        value = value*10 + s[i] - 48;
    return value;
}
int main(void)
{
    char s[] = "1234";
    int res = atoi(s);
    printf("%d\n",res);
    return 0;
}
