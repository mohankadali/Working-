#include <stdio.h>

struct st {
    //declaring function pointer
    int (*p)(int, int) ;
};

int fun ( int a, int b )
{
    return ( a + b ) ;//returning result to called function
}

int main (void)
{
    struct st var ;
    int ret_value ;

    var.p = fun ;//assigning fun address to function pointer

    //calling function
    ret_value = (*var.p)(10, 20) ;

    printf ("%d\n", ret_value) ;
    return 0 ;
}
