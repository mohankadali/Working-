#include <stdio.h>
#if 0 
struct A {
    int a;
    int b:16;
    int c:16;
}s1;
struct B {
    char a:8;
    int b:24;
   // short int c:12;
    int c:12;
}s2;
struct D {
    int a;
    char b:7;
    short int c:10;
    char d:8;
    char e:8;
    char f:8;
}s4;
struct E {
    int a;
    char b:7;
    short int c:10;
    char d:7;
}s5;
struct F {
    char b:6;
    short int a:10;
}s6;
struct G {
    short int a:9;
    char b;
    char c:6;
    char d:6;
    short int e:10;
}s7;
struct J {
// NO elements
}s10;
struct K {
    char a;
    char :0;
    char c:7;
}s11;
struct L {
    int a:6;
    int :0;
    char b:4;
}s12;
struct M {
    int a:6;
    int :27;
    char c;
    char b:4;
}s13;
int main()
{
printf("%d\n",sizeof(s5));
return 0;
}
#endif
#if 0
int main() 
{ 
unsigned int x = -1; 
int y = ~0; 
if (x == y) 
  printf("same"); 
else
  printf("not same"); 
return 0; 
}
#endif
#if 0
int main()
{
  char a = '\012';
  printf("%d", a);
  return 0;
}
#endif
#if 0
int main()
{
  if (sizeof(int) > -1)
    printf("Yes");
  else
    printf("No");
  return 0;
}
#endif
#if 0 
extern int var  =0 ;
int main()
{
  var = 10;
  printf("%d ", var);
  return 0;
}
#endif
#if 0
int main()
{
{
  int var = 10;
}
{
  printf("%d", var); 
}
return 0;
}
#endif
#if 0
int main()
{
int main;
printf("%d\n",main);
return 0;
}
#endif




