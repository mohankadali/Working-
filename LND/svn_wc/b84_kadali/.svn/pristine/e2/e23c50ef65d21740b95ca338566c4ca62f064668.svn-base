#include <stdio.h>
#include "ds_ass1_header.h"

void cir_en_q ( int ele, int *front, int *rear, int *count )
{

    //*front and *rear have to be made to point to the starting index when
    //first enqueued
    if ( ( *front == -1 ) && ( *rear == -1 )) {

        ( *front )++;
        ( *rear )++;
    }

   // if ( (( *rear ) % MAX )  == ( *front ) ) {

    if ( *count == MAX ) {

        printf ("<----------Queue is full--------------> \n");

    } else { 

        if ( *rear == MAX ) {

            *rear = 0;
        }

        cir_q [ ( *rear )++ ] = ele;

        printf ("\nElement is added to the queue \n");

        ( *count )++;
    }
}


























