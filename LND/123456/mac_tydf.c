#include <stdio.h>

typedef char* ptr;

#define PTR char*

int main(void)
{
    ptr a, b, c;
    PTR x, y, z;

    printf( "sizeof a: %u\n", (unsigned) sizeof(a) );
    printf( "sizeof b: %u\n", (unsigned) sizeof(b) );
    printf( "sizeof c: %u\n", (unsigned) sizeof(c) );
    printf( "sizeof x: %u\n", (unsigned) sizeof(x) );
    printf( "sizeof y: %u\n", (unsigned) sizeof(y) );
    printf( "sizeof z: %u\n", (unsigned) sizeof(z) );

    return 0;
}
