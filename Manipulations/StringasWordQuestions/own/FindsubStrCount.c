#include <stdio.h>
int main()
{
        char m[] = "abacabcababcabc";
        char s[] = "abc";
        int i,j;
        static int c=0;
        for(i=0;m[i];i++)
        {
                if (m[i] == s[0])
                {
                        char* temp = m+i;
                        char* sub  = s;

                        while(*sub)
                        {                               
                                if(*sub != *temp)
                                        break;
                                temp++;
                                sub++;
                        }
                        if(*sub == '\0')
                        {
                                c++;        
                        }
                        sub = s;
                }
        }
        printf("%d\n",c);
        return 0;
}
