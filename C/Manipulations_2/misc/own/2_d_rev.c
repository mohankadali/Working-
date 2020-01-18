#include <stdio.h>
#include <string.h>

int main()
{
        char a[] = "hi hello  ii bye ii ii tata" ;
        char b[10][20];
        int n;
        int i,j,k,l;
        j=0,k=0;
        for(i=0;a[i];i++)
        {
                if( a[i] == ' ' )
                {
                        b[j][k] = '\0';
                        j++; 
                        k=0;
                        /*** to remove spaces */
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
        n = j; 
        printf("n =%d, j = %d\n", n,j);     
        // reverse the words //
        /*   char temp[10];
             for(i= 0; i<j;i++,j--)
             {
             strcpy (temp,b[i]);
             strcpy (b[i],b[j]);
             strcpy (b[j],temp);

             } 
         */  
        // to remvoe the word one time //
        /*
           for(i=0;i<7;i++)
           {

           if(strcmp("ii",b[i]) == 0)
           {
           for(;i<7;i++)
           strcpy (b[i],b[i+1]);

           }
           }       
         */
        // remove multiple same consecutive  words //
        //        int iw = 0; 
        for(i=0;i<n+1;i++)
        {
                if(strcmp("ii",b[i]) == 0)
                {
                        for(j=i;j<n+1;j++){
                                strcpy (b[j],b[j+1]);
                        }
                        //                iw++; 
                        n--;          
                        i--;
                }
        }


        for (i=0;i<n+1;i++)
        {
                printf("%s\n",b[i]) ;       
        } 

        return 0;
}
