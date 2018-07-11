#include <stdio.h>
int main()
{
  char a[] = "AaBCBCDFD";

  int i;
  int temp;
  char buf[100] = {};
  for (i=0;a[i];i++)
  {

    temp = a[i] -65;

    if (buf[temp]==0)
    {
      buf[temp] =1 ;
    }
    else {
  
}


  }
  return 0;
}
