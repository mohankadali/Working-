#include<stdio.h> 
int b;
//int b=20;
//printf("hello");
int main(void)
{
/*    int *p;
      int b = 20;
     p = &b;
  */   
    int (*a)[2];
    printf("%p\n", a);
    a++;
    printf("%p\n", a);
//    printf("%d\n",*p);
 //   printf("%p\n",&p);
  //  printf("%p\n",p);

        extern int b;

    printf("%d\n",b);
    return 0;
}
