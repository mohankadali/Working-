#include <stdio.h>
int mystrcmp(char* , char*, int );
int main()
{
        char s1[] = "moha0";
        char s2[] = "moha0";
        int res= mystrcmp(s1,s2,1887);
        if(res == 0)  
                printf("both are same..\n");
        else if(res<0)
                printf("s1 is smaller..\n");
        else 
                printf("s2 is smaller..\n");
        return 0;
}
int mystrcmp(char* s1, char* s2,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                if (s1[i] != s2[i])
                        break;
        }
        if(s1[i] == s2[i])
                return 0;
        else if(s1[i] < s2[i])
                return -1;
        else
                return 1;
}
