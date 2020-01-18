#include <stdio.h>
int main()
{
        char a[] = "ihi elle  elle   hiih madam  h    yyy" ;
        char b[10][20];

        int i,j,k,l;
        j=0,k=0;
        for(i=0;a[i];i++)
        {
                if( a[i] == ' ' )
                {
                        b[j][k] = '\0';
                        j++; 
                        k=0;
                        for(l=i;a[l];l++)
                        {
                                if (a[l] != ' ')
                                        break;
                                else
                                        i++;
                        }
                }
                b[j][k] = a[i];
                k++; 
        }
        b[j][k] = '\0';



        int flag = 0;
        int c=1;
        int x,y;
        for(x=0;x<j;x++)
        {
                for(y=0;y<j;y++)
                {
                        if(x == y)
                                continue;

                        if (strcmp(b[x],b[y]) == 0)
                        {                              
                                flag =  1;
                                printf("dup: %s\n",b[x]) ;       
                                break;
                        }
                        else
                                flag = 0;
                }

                if(flag == 0)
                        printf("no dup: %s\n",b[x]) ;       

        }        

        return 0;
}
