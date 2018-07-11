
#include <stdio.h>
#include "ds_ass1_header.h"

slist * cir_insert_first ( slist **head, int data )
{
    //new node should be created in case if the head is already there
    slist *new;

    //to create a head node
    if ( *head == NULL ) {

        *head = create_node ( data );

        ( * head ) -> next = *head;

        printf ("\nData is added at the BEGINNING of linked list \n\n");

        return *head;

    }
    //to create rest of the node
    slist *ptr = ( *head ); 

    new = create_node ( data );

    //new node is linked with the head node
    new -> next =  ptr -> next;

    ( *head ) -> next = new;

   // *head = new;

    printf ("\nData is added at the BEGINNING of linked list \n\n");

    return *head;
}

slist *cir_insert_last ( slist **head, int data )
{
    //pointer to traverse through the list
    slist *ptr = *head;
    slist *new;

    if ( *head  == NULL ) {

        *head = create_node ( data );

        ( *head ) -> next = *head;

        printf ("\nData is added to the END of the linked list \n\n");

        return *head;
    }

    new = create_node ( data );


    new -> next = ptr -> next;

    ptr -> next = new;

    *head = new;

    printf ("\nData is added to the END of the linked list \n\n");

    return *head;

}

