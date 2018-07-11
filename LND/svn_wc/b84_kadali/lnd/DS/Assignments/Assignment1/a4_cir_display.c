
#include <stdio.h>
#include "ds_ass1_header.h"

void display_cir_q ( int front,int count )
{
    if ( count == 0 ) {

        printf ("\n<---------Queue is empty----------> \n");
        return;

    }


    printf ("\nElements in queue are :  \n\n");

    for ( ; count != 0; count--,front++ ) {

        if (MAX == front) {

            front = 0;
        }

        printf ("%d  ", cir_q [ front] );

    }
    printf ("\n");
}
































