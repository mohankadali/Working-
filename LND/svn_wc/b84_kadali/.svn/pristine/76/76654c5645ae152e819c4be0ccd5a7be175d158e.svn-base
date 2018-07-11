
#include <stdio.h>
#include "ds_ass1_header.h"


void a1 ( void )
{
    int opt;

    int element;

    int top = MAX;

    while ( 1 ) { 

        printf ("\nEnter the options \n1:PUSH\n2:POP\n3:DISPLAY\n4:EXIT\n\n");
        scanf ("%d", &opt );

        switch ( opt ) 
        {
            case 1: 
                printf ("\nEnter the element to be pushed \n");
                scanf ("%d", &element );
                push ( element, &top );
                break;

            case 2:
                pop ( &top );
                break;

            case 3:
                display();
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































