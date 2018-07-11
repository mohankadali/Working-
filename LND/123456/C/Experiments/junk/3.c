#include<stdio.h> 
int y=10;
int main()
{
   volatile  int x=10;
    printf("%d  %d  %d  %d\n",++x,x,x++,++x);
    printf("%d  %d  %d  %d\n",++y,y,y++,++y);
return; 
}
