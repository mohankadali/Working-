#include <stdio.h>

//typedef int INTEGER ;

struct st {

    //using user defined data types

//    typedef int INTEGER ;

    //enum declaration
    enum { TRUE, FALSE } ;
    
    //union declaration
    union u {

        int a ;

    }u_var ;

};

int main (void)
{
    struct st var1 ;
//    INTEGER a ;
    
    //assigning value to enum var
//    var1.var = 8 ;

 //   printf ("%d\n", var1.var) ;
    printf ( "%d\n", TRUE ) ;

    return 0 ;
}
