
#include <stdio.h>
#define ROUNDUP(x,n) ((x+n-1)&(~(n-1)))
  int main()
  {
	int i,j;
	scanf("%d%d",&i,&j);
      	printf("%d\n",ROUNDUP(i,j));
      return 0;
  }
