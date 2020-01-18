#include <stdio.h>
int main()
{
        char a[] = "hi hello bye";
        char b[10][10] ;
        int i,j=0,k=0;
        for (i=0;a[i];i++)
        {       
                if (a[i] == ' ')
                {
                        b[j][k] = '\0';
                        j++;  
                        k=0;              
                        i++; 
                }
                b[j][k] = a[i];
                k++;
        } 
        if(a[i] ==  '\0')
                b[j][k] = '\0';

        char temp[100];
        j=3;
        for (i=0;i<j;i++,j--)
        {
                strcpy(temp,b[i]);
                strcpy(b[i],b[j]);
                strcpy(b[j],temp);
        }


        for(i = 0;i<=3;i++)
                printf(" %s",b[i]);

        return 0;
}
