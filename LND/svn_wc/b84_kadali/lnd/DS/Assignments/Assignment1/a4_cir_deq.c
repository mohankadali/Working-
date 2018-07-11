#include <stdio.h>
#include "ds_ass1_header.h"

void cir_de_q ( int *front, int *rear, int *count )
{

    //to put out the first ele in the q
    if ( ( is_empty ( count ) ) ) {

        if ( *front == MAX ) {

            *front = 0;
        }

        //we need only to increment the *front since we are just printing from the *front position
        cir_q [ ( *front )++ ] = 0 ;

        printf ("\nElement is dequeued \n");
        ( *count ) -- ;

    } else {

        printf ("\n<--------Queue is empty--------> \n");

        return;
    }
}

int is_empty ( int *count )
{
    if ( *count != 0 ) {

        //when empty
        return 1;

    } else {

        //when not empty
        return 0;

    }

}

























