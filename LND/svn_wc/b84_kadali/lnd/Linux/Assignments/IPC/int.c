#include <stdio.h>

int main ()
{
    int a = 134513867 ;
    int *ptr = &a ;

    int j ;

    for (j = 3 ;j>=1 ;j--)
    {
        printf (" %d ",*((char *)ptr +j)) ;
    }
    return 0 ;
}
