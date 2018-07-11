
#include <stdio.h>
#include "ds_ass1_header.h"

void pop_list ( slist **head )
{
    //checks if there is any node present
    if ( *head == NULL ) {

        printf ("\n<---------------Stack list is empty----------------> \n");
        return ;

    }

    //decrementing count when a node is removed
    count--;

    slist *ptr = *head;

    //pointer is made to point to the next node 
    ptr = ptr->next;

    //the node which ptr is pointing is made the head node
    *head = ptr;

    printf ("\nElement is popped from the list \n");
}































