#include <stdio.h>
char* mystrcat(char *,char *);
int main()
{
        char s[] = "mohan";
        char d[] = "krishna";

        char* res = mystrcat(d,s);

        printf("%s\n",res);
        return 0;
}

char* mystrcat(char* d, char* s)
{
        int i,j;
        for(i=0;s[i];i++);
        for(j=0;d[j];j++,i++)
        {
                s[i] = d[j];
        }
        s[i]  = '\0';
        return s;
}
