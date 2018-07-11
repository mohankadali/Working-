#include <stdio.h>
#include "ds_ass1_header.h"

void en_q ( int ele, int *front, int *rear )
{
    //*front and *rear have to be made to point to the starting index when
    //first enqueued
    if ( ( *front == -1 ) && ( *rear == -1 )) {

        ( *front )++;
        ( *rear )++;
    }

    if ( MAX > *rear ) {

        q [ ( *rear ) ++ ] = ele;

        printf ("\nElement is added to the queue \n");

    } else { 

        ///once q is full everything reset
        printf ("\n<--------Queue is full----------> \n");
    }


}


























