
#include <stdio.h>
#include "ds_ass1_header.h"

void cir_display_slist ( slist *head )
{
    //pointer is made to point to the head node
    slist *ptr = head ;

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































