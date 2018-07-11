#include <stdio.h>

#include "ds_ass2_header.h"

void sort (void)
{
    int *arr = ( int * ) calloc ( SIZE, sizeof ( int ) );

    int *temp = ( int * ) calloc ( SIZE, sizeof ( int ) );

    int iter;

    int opt;

    printf ("\nEnter the %d elements in the array \n", SIZE );

   // for ( iter = 0; iter < SIZE; iter++ ) {
    for ( iter = 0; iter < SIZE; iter++ ) {

        scanf ("%d", &arr [ iter ] );

    }


    printf ("\nEnter option: \n\n1:Bubble sort\n2:Selection sort\n3:Insertion sort\n4:Merg sort\n5:Quick sort\n6:Heap sort\n7:Exit\n\n");

    scanf ("%d", &opt );

    switch ( opt ) 
    {

        case 1:
            printf ("\n<------Bubble sort----->\n");

            arr = bubble_sort ( arr, SIZE );

            printf ("\n<-----Sorted------>\n\n");

            display ( arr, SIZE );

            break;

        case 2:
            printf ("\n<------Selection sort----->\n");

            arr = selection_sort ( arr, SIZE );

            printf ("\n<-----Sorted------>\n\n");

            display ( arr, SIZE );

            break;


        case 3:
            printf ("\n<------Insertion sort----->\n");

            arr = insertion_sort ( arr, SIZE );

            printf ("\n<-----Sorted------>\n\n");

            display ( arr, SIZE );

            break;


        case 4:
            printf ("\n<------Merg sort----->\n");

            arr = merg_sort ( arr, temp, 0, SIZE-1 );

            printf ("\n<-----Sorted------>\n\n");

            display ( arr, SIZE );

            break;


        case 5:
            printf ("\n<------Quick sort----->\n");

            arr = quick_sort ( arr, 0, SIZE - 1 );

            printf ("\n<-----Sorted------>\n\n");

            display ( arr, SIZE );

            break;









        default:
            printf ("\nEnter a valid option\n");
            break;

    }
}




