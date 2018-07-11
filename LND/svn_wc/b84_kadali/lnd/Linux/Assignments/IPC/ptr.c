#include <stdio.h>
int main ()
{
    char b ;
    int *a = &b ;
//    b = malloc (1024) ;
  //  b = &a ;
    *a = 1024 ;
//    a++ ;
    printf (" %d ",*((char *)a+1)) ;
    return 0 ;
}
