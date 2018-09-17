#include <stdio.h>
char* mystrcpy(char* , char* );
int main()
{
        char s[] = "mohan";
        char d[10];
        char* res= mystrcpy(d,s);
        printf("%s\n",res);
        return 0;
}
char* mystrcpy(char* d, char* s)
{
        int i;
        for(i=0;s[i];i++)
        {
                d[i] = s[i];
        }
        d[i] = '\0';
        return d;
}
