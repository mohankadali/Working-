#include <stdio.h>
int sum(int x,int y)
{
return printf("%*c%*c",x,'\r',y,'\r');
}
int main()
{
printf("%d\n",sum(10,20));

return 0;
}
