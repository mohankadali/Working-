
#include <stdio.h>
#include "ds_ass1_header.h"

void d_cir_display_dlist ( dlist *head )
{
    //pointer is made to point to the head node
    dlist *ptr = head ;

    if ( head == NULL ) {

        printf ("\n<-------List is Empty-------> \n");
        return;

    }
    printf ("\nElements in the linked list are :  \n\n");

    //loop till the end of the node
    while ( ( ptr != NULL ) ) {

        if ( ptr -> next  == head ) {

            printf ("%d  ", ptr -> next -> data );
            break;

        }

        printf ("%d  ", ptr -> next -> data );
        //to make the pointer to point to the next node
        ptr = ptr->next;
    }

    printf ("\n");
    return;
}































