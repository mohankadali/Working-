#include <stdio.h>
#include <string.h>
void sub(char* m_str,char* s_str)
{
                       

 
        

}
int main()
{
        int c=0,i;
        char main_stir[100] = "hi  hello bye";
        char sub_str[] = "anil";
        for(i=0;main_str[i];i++)
        {
                if(main_str[i] == ' ')
                        c++;
        }

        for (i= 0;i<c;i++)
        {
                sub(main_str,sub_str);
        }
        printf("%d\n",c);
        return 0;
}
