#include<stdio.h> 

//# define    SET_2_BIT(num,p1,p2)    num = ((num ^ (1 << p1)) ^ (1 << p2))
//# define    SET_2_BIT(num,p1,p2,p3)    num = ((num | (1 << p1)) &~(1<<p2)) ^  (1<<p3)
int main(void)
{
  int i;
  unsigned int num = -7 ;
  for(i = 31 ; i>=0 ; i-- )
  {
    printf("%d",num>>i&1);
  }
  printf("\n");
  //  num = num & ~ (~((~0)<<4)) << 0 ;

  //    SET_2_BIT(num,1,0,2);
  for(i = 31 ; i>=0 ; i-- )
  {
    printf("%d",num>>i&1);
  }
  printf("\n");
  return 0;
}

#if 0

#include<stdio.h>
int main(void)
{
    int c;
    int a =10;
    int b=20;
    c = ((((a ^= b) ^ b) & b ) << 1 );
        printf("%d\n",c);
    return 0;
}

#endif
