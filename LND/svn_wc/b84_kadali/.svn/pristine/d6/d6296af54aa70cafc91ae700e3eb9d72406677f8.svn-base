
#include <stdio.h>
#include "ds_ass1_header.h"

slist * insert_first ( slist *head, int data )
{
    //new node should be created in case if the head is already there
    slist *new;

    //to create a head node
    if ( head -> next == NULL ) {

        head -> next = create_node ( data );

        head -> data = ( head -> data ) + 1;

        printf ("\nData is added at the BEGINNING of linked list \n\n");

        return head;

    }
    //to create rest of the node

    new = create_node ( data );

    //new node is linked with the head node
    new -> next =  head -> next;

    head -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added at the BEGINNING of linked list \n\n");

    return head;
}

slist *  insert_last ( slist *head, int data )
{
    //pointer to traverse through the list
    slist *ptr = head;
    slist *new;

    if ( head -> next  == NULL ) {

        head -> next = create_node ( data );

        head -> data = ( head -> data ) + 1;

        printf ("\nData is added to the END of the linked list \n\n");

        return head;
    }

    new = create_node ( data );

    //while loop will break when the node is pointing to NULL 
    while ( ptr->next != NULL ) {

        ptr = ptr->next;

    }

    //now make the last nopde point to the new node
    ptr->next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added to the END of the linked list \n\n");

    return head;

}



slist *insert_at_pos ( slist *head, int data, int pos )
{

    int count = 0;

    slist *ptr = head;

    slist *new = create_node ( data );

    //error condition when position is an invalid pos 
    //count will have the count of number of nodes present
    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;
        count ++;

    }
    //    printf ("\ncount is : %d \n", count );

    //pointer ptr is made to point back to the head node
    ptr = head;

    //if will check if there is any node present
    if ( head -> next != NULL ) {
        //we have to move the pointer ptr to the first node which is after the DUMMY header node so point it to next node
        ptr = ptr -> next;

        //if there are nodes more than 1 and if you want to add the node at pos 0 
        if ( pos == 0 ) {

            new -> next = head -> next;

            head ->next = new ;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added at the POSITION of the linked list \n\n");

            return head;
        }

    } else {

        //when is empty at want to add node at pos 0

        if ( pos == 0 ) {

            head -> next = new;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added at the POSITION of the linked list \n\n");

            return head;

        } else { 

            printf ("\n<-------Node cannot be added at the position you specified------------> \n\n<-------List is empty----->\n");
        }
    }

    if ( pos >  count ) {

        printf ("\n<--------Node cannot be added at POSITION---------> \n");
        return head;
    }
    while  ( -- pos ) {

        ptr  = ptr -> next  ;
    } 

    new -> next = ptr -> next;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added at the POSITION of the linked list \n\n");

    return head;
}


slist *insert_before_pos ( slist *head, int data, int pos )
{
    int count = 0;

    slist *ptr = head;

    slist *new = create_node ( data );

    //error condition when position is an invalid pos 
    //count will have the count of number of nodes present
    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;

        count ++;
    }
    //  printf ("\ncount is : %d \n", count );

    //pointer ptr is made to point back to the head node
    ptr = head;

    //if will check if there is any node present
    if ( head -> next != NULL ) {

        //we have to move the pointer ptr to the first node which is after the DUMMY header node so point it to next node
        ptr = ptr -> next;

        //if there are nodes more than 1 and if you want to add the node at pos 0 
        if ( pos == 0 ) {

            printf ("\n<-------Node cannot be added before the given POSITION------->\n");
            return head;
        }

    } else {

        printf ("\n<-------Node cannot be added before the position you specified------------> \n\n<-------List is empty----->\n");

        return head;
    }

    if ( ( pos + 1 ) >  count ) {

        printf ("\n<--------Node cannot be added before specified POSITION---------> \n");
        return head;
    }

    while  ( -- pos ) {

        ptr  = ptr -> next  ;
    } 

    new -> next = ptr -> next;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added before the POSITION of the linked list \n\n");

    return head;
}


slist *insert_after_pos ( slist *head, int data, int pos )
{


    int count = 0;

    slist *ptr = head;

    slist *new = create_node ( data );

    //error condition when position is an invalid pos 
    //count will have the count of number of nodes present
    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;
        count ++;
    }
    //    printf ("\ncount is : %d \n", count );
    //pointer ptr is made to point back to the head node
    ptr = head;

    //if will check if there is any node present
    if ( head -> next != NULL ) {

        //we have to move the pointer ptr to the first node which is after the DUMMY header node so point it to next node
        ptr = ptr -> next;

        //if there are nodes more than 1 and if you want to add the node after  pos 0 
        if ( pos == 0 ) {

            new -> next = ptr -> next;

            ptr ->next = new ;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added after the POSITION of the linked list \n\n");

            return head;
        } 

    } else {

        printf ("\n<-------Node cannot be added after the position you specified------------> \n\n<-------List is empty----->\n");

        return head;
    }

    if ( pos >=  count ) {

        printf ("\n<--------Node cannot be added after the POSITION---------> \n");
        return head;
    }

    //ptr is made to move till the pos 
    while  ( pos -- ) {

        ptr  = ptr -> next  ;

    } 

    new -> next = ptr -> next;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added after the POSITION of the linked list \n\n");

    return head;
}


slist *insert_before_num ( slist *head, int data, int num )
{
    slist *ptr = head;

    slist *new = create_node ( data );

    if ( head -> next == NULL ) {

        printf ("\n<---------NO Nodes present-----------> \n");
        return NULL;

    } else {

        ptr = ptr -> next ;
    }

    while ( ptr -> data != num) {

        if ( ptr -> next == NULL ) {

            printf ("\n<-----Data not present---->\n");
            return head;
        }

        if ( ( ptr -> next -> data )  == num ) {

            new -> next = ptr -> next ;

            ptr -> next = new;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added before the NUMBER of the linked list \n\n");

            return head;
        }

        ptr = ptr -> next;
    }

    //if first nodes having the data

    new -> next = head -> next;

    head -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added before the NUMBER of the linked list \n\n");

    return head;
}


slist *insert_after_num ( slist *head, int data, int num )
{
    slist *ptr = head;

    slist *new = create_node ( data );

    if ( head -> next == NULL ) {

        printf ("\n<---------NO Nodes present-----------> \n");
        return NULL;

    } else {

        ptr = ptr -> next ;
    }

    while ( ptr -> data != num) {

        if ( ptr -> next == NULL ) {

            printf ("\n<-----Data not present---->\n");
            return head;
        }

        ptr = ptr -> next;
    }

    //if first nodes having the data

    new -> next = ptr -> next;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added after the NUMBER of the linked list \n\n");

    return head;
}


slist *insert_middle ( slist *head, int data )
{

    slist *ptr = head;
    slist *prev = head;

    slist *new = create_node ( data );

    if ( head -> next == NULL ) {

        printf ("\n<-----List is empty----->\n");
        return head;

    } else {
        //if the list is not empty both pointers are made to point to the first node

        ptr = ptr -> next;
        prev = prev -> next;
    } 

    //this loop will work for even number of nodes
    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;

        if ( ptr -> next == NULL ) {

            new -> next = prev -> next;

            prev -> next = new;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added at the MIDDLE of the linked list \n\n");

            return head;

        } else {

            ptr = ptr -> next;

            if ( ptr -> next != NULL ) { 

                prev = prev -> next;
            }

        }

    }
    //this will work when there are odd number of nodes

    new -> next = prev -> next;

    prev -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added at the MIDDLE of the linked list \n\n");

    return head;   
}


slist *insert_penultimate ( slist *head, int data )
{
    slist *ptr = head;

    slist *new = create_node ( data );

    if ( head -> next == NULL ) {

        printf ("\n<-------LIST IS EMPTY-------> \n");

        return head;

    }
    while ( ptr -> next != NULL ) {

        if ( ptr -> next -> next == NULL ) {

            new -> next = ptr -> next;

            ptr -> next = new;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added at the PENULTIMATE of the linked list \n\n");

            return head;
        }

        ptr = ptr -> next;
    }

    return head;
}


slist *create_node ( int data )
{
    //dynamically alocating memory to create node
    slist *new = ( slist * ) malloc ( sizeof ( slist ));

    new->data = data;

    new->next = NULL;

    return new;
}

