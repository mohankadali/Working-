#include <stdio.h>
int main()
{ 
        int k = 10 ; 
const int *p ;
        p = &k ; 
        *p = 20 ; 
        printf("\n %d", k );
}
