
#include <stdio.h>
#include "ds_ass1_header.h"


void a3 ( void )
{
    int opt;

    int element;

    int front = -1;

    int rear = -1;

    while ( 1 ) { 

        printf ("\nEnter the options \n1:Enqueue\n2:Dequeue\n3:DISPLAY\n4:EXIT\n\n");
        scanf ("%d", &opt );

        switch ( opt ) 
        {
            case 1: 
                printf ("\nEnter the element to be enqueued \n");
                scanf ("%d", &element );
                en_q ( element, &front, &rear );
                break;

            case 2:
                de_q ( &front, &rear );
                break;

            case 3:
                display_q ( &front, &rear );
                break;


            case 4: 
                return;
                break;

            default :
                printf ("\nEnter a valid option \n");
                break;


        }
    }
}































