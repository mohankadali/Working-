#include <stdio.h>
#include "ds_ass1_header.h"

void de_q ( int *front, int *rear )
{

    //to put out the first ele in the q
    if ( *front <= *rear ) {

        //we need only to increment the *front since we are just printing from the *front position
        q [ ( *front )++ ] = 0;

        if ( *front < *rear ) {

            printf ("\nElement is dequeued \n");
            return ;

        } else if ( *front == *rear ) {

            printf ("\nAll the elements are dequeued \n"); 
            return;
        }
    }
    //validation
    if ( ( *front > *rear ) || ( *front == -1 ) ) {

        printf ("\n<--------Queue is empty--------> \n");
        printf ("\n" );
        *front = -1;
        *rear = -1;
        return;
    }
}


























