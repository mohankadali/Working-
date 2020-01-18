#include <stdio.h>
char* mystrstr(const char*, const char*);
int main()
{
        char s1[] = "anil kumar";
        char s2[] = "nil k";

        char*p = mystrstr(s1,s2);

        if(p == NULL)
                printf("sub string not found..\n");
        else
                printf("found str:%s at address %p\n",s2,p);
        return 0;
}
char *mystrstr(const char*s1 ,const char*s2)
{
        int i,j;
        int addr;
        for (i=0;s1[i];i++)
        {
                if (s1[i] == s2[0]) 
                {
                        addr = i;
                        for (j=i+1;s2[j];j++)
                        {
                                if(s2[j]!=s1[j+i])
                                        break;
                        } 
                }
        }
        if (s2[j] == '\0'){
                return s1+addr;
        }
        else
        {
                return NULL;
        }
}


