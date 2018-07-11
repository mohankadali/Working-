#include<stdio.h> 
int main(void)
{
  int a=1;
  while(a = 3,printf("%d\n",a),a = 100,a++)
  {
    printf("%d\n",a);
  }
  return 0;
}

