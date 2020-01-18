#include <stdio.h>
char* mystrchr(const char*,int);
int main()
{
        char a[] = "mohan";
        int c = 'q';
        char* res = mystrchr(a,c);
        printf("address:%p\n",res);
        return 0;
}
char* mystrchr(const char* s,int c)
{
        int i;
        char* p;
        for(i=0;s[i];i++)
        {
                if (s[i]==c)
                {
                p = s+i;       
                }
        }
return p;
}

