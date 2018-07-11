#include<stdio.h> 
main()
{

    int *p;

    p = malloc(10);

    *p= 3435820;

    int *q=p ;
 //   *q =45;
    int *r=p ;


//    free(p);
    free(q);
  //  p = NULL;

    *q =45;
    printf("%d\n",*r);
    printf("%d\n",*q);

    printf("%d\n",*p);
}
