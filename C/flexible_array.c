#include <stdio.h>
struct s
{
  int  a ;
  int arr[] ;
  int b ;
}ok ;

int main ()
{
  printf ( "%d"  , sizeof (ok ) );
  return 0 ;
}
