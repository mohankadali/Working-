#include<stdio.h> 
main()
{
char a[19]="global edge";
char *t=&a[0];
char *t1=&a[4];
//printf("%c   %c   ",*ptr1,*ptr2);
printf("%c   ",t-t1);
}
