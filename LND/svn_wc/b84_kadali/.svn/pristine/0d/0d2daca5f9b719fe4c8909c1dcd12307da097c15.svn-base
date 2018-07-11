#include <stdio.h>

#include "ds_ass2_header.h"

int *bubble_sort ( int *arr, int size )
{

    int iter1;

    int iter2;

    int temp;


    for ( iter1 = 0; iter1 < size - 1; iter1++ ) {

        for ( iter2 = 0; iter2 < size - 1 - iter1; iter2++ ) {

            if ( *(arr + iter2 ) > *(arr + ( iter2 + 1 ) ) ) {

                temp = *(arr + iter2 );

                *(arr + iter2 ) = *(arr + ( iter2 + 1 ));

                *(arr + ( iter2 + 1 )) = temp;

            }
        }
    }

    return arr;
}



