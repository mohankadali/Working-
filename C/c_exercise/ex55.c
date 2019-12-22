#include<stdio.h>
const int b = 20;	//It will stored in .rodata in elf
const int c;		//It won't store in .rodata in elf	
int main()
{
   int *ptr;
   ptr = &b;
   *ptr = 10;
   printf("%d",c);
    return 0;
}
