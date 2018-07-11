#include <stdio.h>
#include "ds_ass2_header.h"

int *insertion_sort ( int *arr , int size )
{

    int iter1;

    int iter2;

    int temp;

    int indx;

    for ( iter1 = 1; iter1 < size ; iter1++ ) {

        indx =  arr [ iter1 ];

        for ( iter2 = iter1 - 1; iter2 >= 0 ; iter2-- ) {

            if ( *(arr + iter2 ) >  indx ) {


                temp = *(arr + iter2 );

                *(arr + iter2 ) = indx;

                *(arr + ( iter2 + 1 ) ) = temp;

            }
        }

    }

    return arr;
}


