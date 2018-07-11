#include <stdio.h>
#include <stdlib.h>
/*
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
int b;*/
int var[10];  /* Uninitialized so in .bss */
int main ()
{
  var[0] = 20 ;
}
