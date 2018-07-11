
#include <stdio.h>
#include "ds_ass1_header.h"

slist * cir_delete_first ( slist **head  )
{
    slist *ptr = *head;
    //to create a head node
    if ( *head == NULL ) {

        printf ("\n<-------List is Empty------->\n\n");

        return *head;

    }
    //to create rest of the node

    ptr = ptr -> next;

    if ( ptr == *head ) {

        free ( ptr );

        printf ("\nNode is deleted at the BEGINNING of linked list \n\n");

        return NULL;

    }

    ptr = ( *head ) -> next;

    ( *head ) -> next = ptr -> next;

    free ( ptr );

    printf ("\nNode is deleted at the BEGINNING of linked list \n\n");

    return *head;
}


slist * cir_delete_last ( slist **head  )
{
    //pointer to traverse through the list
    slist *ptr = *head;

    slist *ptr2 = NULL;

    if ( *head == NULL ) {

        printf ("\n<-------List is Empty------->\n\n");

        return *head;
    }

    //while loop will break when the node is pointing to NULL 
    while ( ptr->next != NULL ) {

        if ( ptr == *head ) {

            free ( ptr );

            printf ("\nNode is deleted at the BEGINNING of linked list \n\n");

            return NULL;

        }

        if ( ptr -> next == *head ) {

            //to free the node , so took second pointer
            ptr2 = ptr -> next;

            ptr -> next = ( *head ) -> next;

            *head = ptr;

            free ( ptr2 );

            printf ("\nNode is deleted at the END of the linked list \n\n");

            return *head;

        }

        ptr = ptr->next;
    }

    return *head;
}
