#include <stdio.h>
#include <string.h>
char* rec(char *str,int i )
{
        static int j;
        char temp;
        if(j<i)
        {

                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i--,j++;
                rec(str,i);  
        }
        else
                return str;
}
int main()
{
        char str[] = "madam";
        char *p;
        int i;
        //        for(i=0;str[i];i++);
        //      i = i-1;
        i= strlen(str);
        i= i-1;
        p=rec (str,i);
        printf("%s \n",p);
        return 0;
}
