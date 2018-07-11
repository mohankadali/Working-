#include <stdio.h>

#include "ds_ass2_header.h"

int *merg_sort (int *arr, int *temp, int low, int high )
{

    //int temp;

    int mid = ( low + high ) / 2;

    if  ( low < high ) {

        merg_sort ( arr, temp, low, mid );
        merg_sort ( arr, temp, mid + 1, high );
        merg ( arr, temp, low, mid, high );

    }

    return arr;
}





int *merg ( int *arr, int *temp,  int low, int mid, int high )
{


    int low_end = mid;
    int pos = low;

    int high_start = mid + 1;

    int element = ( high - low ) + 1;

    //static int *temp = ( int * ) malloc ( SIZE * sizeof ( int ) );


    while (( low <= low_end ) && ( high_start <= high )) {

        if ( arr [ low ] > arr [ high_start ] ) {

            temp [ pos++ ] = arr [ high_start ];
            high_start++;

        } else {

            temp [ pos++  ] = arr [ low ];
            low++;
        }
    }

    while ( low <= low_end ) {

        temp [ pos++ ] = arr [ low ];
        low++;

    }

    while ( high_start <= high ) {

        temp [ pos++ ] = arr [ high_start ];
        high_start++;

    }

    while ( element ) {

        arr [ high ] = temp [ high ];
        high --;
        element --;
    }


      return arr;
}





