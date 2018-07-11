#include <stdio.h>
#include "ds_ass2_header.h"

int searching (void)
{
    int *arr = ( int * ) calloc ( SIZE, sizeof ( int ) );

    int ret_val;

    int iter;

    int search_num;

    int opt;

    printf ("\nEnter the %d elements in the array \n", SIZE );

    for ( iter = 0; iter < SIZE; iter++ ) {

        scanf ("%d", &arr [ iter ] );

    }


    printf ("\nEnter option : \n1:Liner search\n2:Binary search\n");
    scanf ("%d", &opt );

    switch ( opt ) 
    {

        case 1:
            printf ("\n<-----Linear search-----> \n");
            printf ("\nEnter the number to be searched \n");
            scanf ("%d", &search_num );

            printf ("\ninside a : %p \n", arr );

            ret_val = linear_search ( arr, search_num, SIZE );

            if (  ret_val != -1  ) {

                printf ("\nNumber is found at position : %d \n", ret_val );

            } else {

                printf ("\nNumber not found \n");

            }
            break;

        case 2:
            printf ("\n<-----Binary search-----> \n");
            printf ("\nEnter the number to be searched \n");
            scanf ("%d", &search_num );

            ret_val = binary_search ( arr, search_num, SIZE );

            if (  ret_val != -1  ) {

                printf ("\nNumber is found at position : %d \n", ret_val );

            } else {

                printf ("\nNumber not found \n");

            }
            break;


        default:
            printf ("\nEnter a valid option \n");

            break;
    }
    printf ("\n \n");
    return 0;
}


