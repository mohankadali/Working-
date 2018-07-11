#include <stdio.h>
#include "ds_ass2_header.h"

int *selection_sort ( int *arr , int size )
{

    int iter1;

    int iter2;

    int temp;


    for ( iter1 = 0; iter1 < size - 1; iter1++ ) {

        for ( iter2 = iter1 + 1; iter2 < size; iter2++ ) {

            if ( *(arr + iter1 ) > *(arr + iter2 ) ) {

                temp = *(arr + iter1 );

                *(arr + iter1 ) = *(arr + iter2 );

                *(arr + iter2 ) = temp;

            }
        }
    }

    return arr;
}


