#include <stdio.h>
char* mystrcpy(char* , char* ,int );
int main()
{
        char s[] = "mohan";
        char d[10];
        char* res= mystrcpy(d,s,4);
        printf("%s\n",res);
        return 0;
}
char* mystrcpy(char* d, char* s,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                d[i] = s[i];
        }
        d[i] = '\0';
        return d;
}
