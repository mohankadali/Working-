
#include <stdio.h>
#include "ds_ass1_header.h"

dlist * d_cir_insert_first ( dlist **head, int data )
{
    //new node should be created in case if the head is already there
    dlist *new;

    //to create a head node
    if ( *head == NULL ) {

        *head = d_create_node ( data );

        ( * head ) -> next = *head;
        ( * head ) -> prev = *head;

        printf ("\nData is added at the BEGINNING of linked list \n\n");

        return *head;

    }
    //to create rest of the node
    dlist *ptr =  *head ; 

    new = d_create_node ( data );

    //new node is linked with the head node
    new -> next =  ptr -> next;

    ptr -> next -> prev = new;

    new -> prev = *head;

    ( *head ) -> next = new;

   // *head = new;

    printf ("\nData is added at the BEGINNING of linked list \n\n");

    return *head;
}

dlist *d_cir_insert_last ( dlist **head, int data )
{
    //pointer to traverse through the list
    dlist *ptr = *head;
    dlist *new;

    if ( *head  == NULL ) {

        *head = d_create_node ( data );

        ( *head ) -> next = *head;

        ( * head ) -> prev = *head;

        printf ("\nData is added to the END of the linked list \n\n");

        return *head;
    }

    new = d_create_node ( data );


    new -> next = ptr -> next;

    ptr -> next -> prev = new;

    new -> prev = *head;

    ( *head ) -> next = new;

    *head = new;

    printf ("\nData is added to the END of the linked list \n\n");

    return *head;

}

