#include <stdio.h>
#if 0
int main()
{
  static int i=5;
  if(--i){
    printf("%d ",i);
    main();
  }
}
#endif
#if 0
int main()
{
typedef static int *i; //error
int j;
i a = &j;
printf("%d", *a);
return 0;
}
#endif
#if 0
int main()
{
typedef int i;
i a = 0;
printf("%d", a);
return 0;
}
#endif 
#if 0
int fun()
{
static int num = 16;
return num--;
}

int main()
{
for(fun(); fun(); fun())
  printf("%d ", fun());
return 0;
}
#endif
#if 0
int main() 
{ 
int x = 10; 
static int y = x; 

if(x == y) 
  printf("Equal"); 
else if(x > y) 
  printf("Greater"); 
else
  printf("Less"); 
return 0; 
}
#endif
#if 0
int f(int n) 
{ 
static int i = 1; 
if (n >= 5) 
  return n; 
n = n+i; 
i++; 
return f(n); 
}
#endif
#if 0
int main()
{
  extern int i;
  printf("%d ", i);
  {
    int i = 10;
    printf("%d ", i);
  }
}
i=1;
#endif
#if 0
int fun(int n)
{
  static int s = 0;
  s = s + n;
  return (s);
}
int main()
{
  int i = 2, x;
  while (i > 0)
  {
    x = fun(i);
    i--;
  }
  printf ("%d ", x);
  return 0;
}
#endif
#if 0 
char *fun()
{
 static char arr[1024];
  return arr;
}

int main()
{
  char *str = "global edge";
  strcpy(fun(), str);
  str = fun();
  strcpy(str, "global edge");
  printf("%s", fun());
  return 0;
}
#endif
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




