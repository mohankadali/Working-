#include <stdio.h>

struct st{
short int c;
short int d;
short int e;
};

int main()
{

  struct st a;

  printf("%d\n",sizeof(a));
  return 0;
}

