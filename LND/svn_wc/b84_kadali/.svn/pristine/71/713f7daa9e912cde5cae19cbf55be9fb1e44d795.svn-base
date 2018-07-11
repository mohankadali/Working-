#include <stdio.h>
#include "ds_ass2_header.h"

int *quick_sort ( int *ar, int low, int high )
{

    //first value in the array is taken as pivot
    int pivot = ar [ low ];

    //i takes the index of the second element
    int i = low + 1;

    // j takes the index of the last element
    int j = high;

    //loop works till i crosses j value
    while ( i <= j ) {

        // checks if value at index i is < pivot then increments i index by 1
        if ( ar [ i ] < pivot ) {

            i++;
            continue;

        }

        // checks if value at index j is > pivot then decrements j index by 1
        if ( ar [ j ] > pivot ) {

            j--;
            continue;

        }

        // when both the aboves condition fails
        // checks if i index crosses j or not
        if ( i < j ) {

            swap ( ar, i, j );

            i++;
            j--;

        } else {

            i++;
        }
    }

    //swap to bring the pivot to its right index
    swap ( ar, low, j );

    //calls same function for the left sublist of pivot
    if ( ( j - 1 ) >= low ) {

        quick_sort ( ar, low, (j - 1) );

    }

    //calls same function for the right sublist of pivot
    if ( ( j + 1 ) <= high ) {

        quick_sort ( ar, ( j + 1 ), high );
    }

    return ar;
}



void swap ( int *ar, int indx1, int indx2 )
{

    int temp;

    temp = ar [ indx1 ];

    ar[ indx1 ] = ar [indx2 ];

    ar [indx2 ] = temp;

}





        
