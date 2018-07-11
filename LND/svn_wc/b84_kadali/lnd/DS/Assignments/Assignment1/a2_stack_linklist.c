
#include <stdio.h>
#include "ds_ass1_header.h"


void a2 ( void )
{
    int opt;

    int element;

    count = 0;

    slist *head = NULL ;

    while ( 1 ) { 

        printf ("\nEnter the options \n1:PUSH to list\n2:POP from list\n3:DISPLAY\n4:EXIT\n\n");
        scanf ("%d", &opt );

        switch ( opt ) 
        {
            case 1: 
                printf ("\nEnter the element to be pushed into linked list \n");
                scanf ("%d", &element );
                push_list ( &head, element );
                break;

            case 2:
                pop_list ( &head );
                break;

            case 3:
                display_list ( head );
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
























