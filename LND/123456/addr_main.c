#include<stdio.h> 
int main(void)
{

int *p = &main;
printf("%p\n",p);
printf("%p\n",*p);
printf("addr of main = %p\n",main);
printf("addr of main = %p\n",&main);
return 0;
}
