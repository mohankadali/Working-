#include <stdio.h>
#if 1 
int main ()
{
const int a = 10;
        int *p = &a;
        *p = 5;
        printf ( " %d", a);
}
#endif
#if 0
int main ()
{
        int a = 10 ;
int         *p = &a;
        (*p)++;
        printf ("%d",a) ;
}
#endif
