#include <stdio.h>

int main(void)
{
  int value;
  int *pv;
  int **ppv;
  int ***pppv;
  int a[100];
  value = 32;
  pv = &value;
  ppv = a;
  pppv = ppv + 1;
  
  printf("value = %u\n", value );
  printf("*pv   = %u\n", *pv );
//  printf("*(*ppv) = %u\n", *(*ppv) );
 // printf("*(*(*pppv)) = %u\n", *(*(*pppv)) );

  printf("value = %u\n", value );
  printf("pv   = %u pv + 1 = %u\n", pv ,pv + 1);
  printf("ppv  = %u ppv + 1 = %u\n", ppv, ppv + 1 );
  printf("pppv = %u pppv + 1 = %u\n", pppv , pppv + 1 );
   return 0;
}

