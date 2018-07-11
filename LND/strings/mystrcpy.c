#include<stdio.h> 
int* strcp(char *q, char *p )
{
    int i,j;
    int *temp;
    for(i = 0;  p[i]   ;i++)
    {
        if(q[0]==p[i])
        {
            temp = (int*)&p[i];
                for(j=0;q[j];j++)
                {
                    if(p[i]!=q[j])
                        break;
                }
        }
    }
    if(q[j] == '\0')
        return temp;
    else
       return NULL; 
}
int main(void)
{
    int *res;
    char p[] = "hello";
    char q[] = "ir";
    res =  strcp(q,p);
    printf("%p\n",res);
    return 0;
}
