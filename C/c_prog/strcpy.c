#include<stdio.h>
#include<string.h>
char* strcp(char*,char*);
int main()
{

    char s[] = "hello\0world ",d[10];

    char* res = strcp(d,s);

    printf("%s\n",res);
    return 0;
}
char* strcp(char* d,char* s)
{
    size_t i;

    for(i=0;s[i]!='\0';i++)
    {
        d[i] = s[i];
    }
    d[i] = '\0';
    return d;
}
