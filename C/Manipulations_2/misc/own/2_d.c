#include <stdio.h>
int palindrome(char a[] )
{
        static int c=0;  
        int i;
        int j;
        int temp;
        for (i=0;a[i];i++);
        j = i-1;
        for(i=0;i<j;i++,j--)
        {
                if (a[i]!= a[j])
                {
                        break; 
                }
        }
        if(i >= j)        
                return ++c;
}
int main()
{
        char a[] = "ihi elle              eye    hiih madam  h      yyy" ;
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

        int c;
        for (i=0;i<6;i++)
        {
                c = palindrome(b[i]);
        } 
        printf("%d   ",c) ; 


        /*        for (i=0;i<4;i++)
                  {
                  printf("%s",b[i]);
                  }
         */
        return 0;
}
