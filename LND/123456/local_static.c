#include <stdio.h>
extern int (*p[3])(void);

int main()
{
printf("x= %d\n",p[0]());
printf("x= %d\n",p[1]());
printf("x= %d\n",p[2]());
 return 0;
}
