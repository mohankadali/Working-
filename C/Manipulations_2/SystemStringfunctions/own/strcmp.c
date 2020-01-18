#include <stdio.h>
int mystrcmp(char* , char* );
int main()
{
        char s1[] = "mohan";
        char s2[] = "moha0";
        int res= mystrcmp(s1,s2);
        if(res == 0)  
                printf("both are same..\n");
        else if(res<0)
                printf("s1 is smaller..\n");
        else 
                printf("s2 is smaller..\n");
        return 0;
}
int mystrcmp(char* s1, char* s2)
{
        int i;
        for(i=0;s1[i];i++)
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
