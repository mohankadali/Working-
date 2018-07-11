
#include <stdio.h>
#include "ds_ass1_header.h"


void push_list ( slist **head, int ele )
{
    //new node should be created in case if the head is already there
    slist *new;

    //to create a head node
    if ( *head == NULL ) {

        *head = create_node ( ele );

        return ;

    }

    if ( count == MAX ) {

        printf ("\n<--------------Stack is full---------------> \n");
        return ;
    }

    //to create rest of the node

    new = create_node ( ele );

    //new node is linked with the head node
    new->next = *head;

    //new node is made the head node
    *head = new;

    printf ("\nElement is pushed to the linked stack \n");
    return ;
}

/*
slist *create_node ( int ele )
{
    //dynamically alocating memory to create node
    slist *new = malloc ( sizeof ( slist ));

    new->data = ele;
    new->next = NULL;

    //increament count when node is added 
    count++;

    return new;

}


*/



























