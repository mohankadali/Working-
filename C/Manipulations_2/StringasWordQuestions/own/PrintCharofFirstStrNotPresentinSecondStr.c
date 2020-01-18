#include <stdio.h>
int main()
{
        const char* x = "hello";
        const char* y = "hi";
        const char* z = y;
        int flag = 0;
        int i,j;

        for(i=0;x[i];i++)
        {
                for(j=0;y[j];j++)
                {

                        if(x[i] == y[j])
                        {                 
                                flag = 1;
                                break;
                        }
                        else
                        {
                                flag = 0;
                        }
                }
                y = z;
                if(flag == 0)
                {
                        printf("unique char :%c \n",x[i]);
                }

        }
        return 0;
}
