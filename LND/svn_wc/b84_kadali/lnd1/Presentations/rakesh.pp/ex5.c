//usage of pragma directive and __attribute

#include <stdio.h>

//using pragma directive
//#pragma pack (1)

//declaring a structure
struct st {
    char c;// __attribute__((aligned(1))) ;
    int a;// __attribute__((aligned(1))) ;
    char b;// __attribute__((aligned(1))) ;
    char d;// __attribute__((aligned(1))) ;
    char e;// __attribute__((aligned(1))) ;
};// __attribute__((packed)) ;

int main (void)
{
    //printing size of structure
    printf ("size : %d\n", sizeof ( struct st ) ) ;

    return 0 ;
}
