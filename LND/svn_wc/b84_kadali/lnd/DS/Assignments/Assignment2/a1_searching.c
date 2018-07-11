#include <stdio.h>
#include "ds_ass2_header.h"

int linear_search ( int *arr, int num, int size )
{

    int indx = 0;

    printf ("\n a : %p \n", arr);
   while ( size -- ) {

        if ( arr [ indx ] == num ) {

            return indx;

        }
        indx ++;
    }

    return -1;
}

int binary_search ( int *arr, int num, int size )
{
    int iter;

    int low = 0;

    int high = size - 1;

    int mid = ( low + high ) / 2;

    arr = sorting ( arr, size );

    printf ("\nSorted array is : \n");

    for ( iter = 0; iter < size; iter++ ) {

        printf ("%d ", arr [ iter ] );
    }

 
    while (( arr [ mid ] != num ) && ( low <= high ) ) {

        mid = ( low + high ) / 2;

        if ( arr [ mid ] > num ) {

            high = mid - 1;

        } else {

            low = mid + 1;

        }
    }

//    printf ("\nmid : %d \n", mid);

    if ( arr [ mid ] == num ) {

        return mid;

    } else {

        return -1;

    }
}




        





int *sorting ( int *arr , int size )
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


