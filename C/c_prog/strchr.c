#include<stdio.h>
char* strch(const char*,int);
int main(void)
{
    char s[] = "hello";
    printf("s[0] = %p\n",s);
    char* p = strch(s,'l');
    if(p)
    {
        printf("address = %p\n",p);
    }
    else
    {
        printf("not found \n");
    }
    return 0;
}
char* strch(const char*s,int ch )
{
    char* p;
    int i;
    for(i=0;s[i];i++)
    {
        if(s[i] == ch)
            p = s+i;
    }
    return p;
}
