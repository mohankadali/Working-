#include <stdio.h>

#include "ds_ass2_header.h"

void display ( int * arr, int size )
{

    int iter = 0;

    for ( iter = 0; iter < size; iter++ ) {

        printf ("%d ", *( arr + iter ) );

    }
    printf ("\n \n");

    return;
}


