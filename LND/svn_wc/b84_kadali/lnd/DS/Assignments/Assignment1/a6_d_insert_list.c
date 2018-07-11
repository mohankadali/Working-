#include <stdio.h>

#include "ds_ass1_header.h"

dlist *d_insert_first ( dlist *head , int data )
{

    dlist *ptr = head;

    dlist *new = d_create_node ( data );


    if ( head -> next == NULL ) {

        head -> next = new;

        new -> prev = head;

    } else {

        ptr = ptr -> next;

        head -> next = new;

        new -> prev = head;

        new -> next = ptr;

    }

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added at the BEGINNING of linked list \n\n");

    return head;
}


dlist *d_insert_last ( dlist *head , int data )
{

    dlist *ptr = head;

    dlist *new = d_create_node ( data );


    if ( head -> next == NULL ) {

        printf ("\n<-------List is Empty-------> \n");

        return head;

    } else {

        ptr = ptr -> next;

    }

    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;

    }

    ptr -> next = new;

    new -> prev = ptr;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added to the END of the linked list \n\n");

    return head;
}



dlist *d_insert_at_pos ( dlist *head, int data, int pos )
{

    int count = 0;

    dlist *ptr = head;

    dlist *new = d_create_node ( data );

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

            new -> next = ptr;

            new -> prev = head;

            ptr -> prev = new;

            head -> next = new;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added at the POSITION of the linked list \n\n");

            return head;
        }

    } else {

        //when is empty at want to add node at pos 0

        if ( pos == 0 ) {

            head -> next = new;

            new -> prev = head;

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

    if ( pos == count ) {

        head = d_insert_last ( head , data );

        return head;

    }

    while  ( -- pos ) {

        ptr  = ptr -> next  ;

    } 

    new -> next = ptr -> next;

    ptr -> next -> prev = new;

    new -> prev = ptr;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added at the POSITION of the linked list \n\n");

    return head;
}


dlist *d_insert_before_pos ( dlist *head, int data, int pos )
{
    int count = 0;

    dlist *ptr = head;

    dlist *new = d_create_node ( data );

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

    ptr -> next -> prev = new;

    new -> prev = ptr;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added before the POSITION of the linked list \n\n");

    return head;
}


dlist *d_insert_after_pos ( dlist *head, int data, int pos )
{


    int count = 0;

    dlist *ptr = head;

    dlist *new = d_create_node ( data );

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

    } else {

        printf ("\n<-------Node cannot be added after the position you specified------------> \n\n<-------List is empty----->\n");

        return head;
    }

    if ( pos >=  count ) {

        printf ("\n<--------Node cannot be added after the POSITION---------> \n");
        return head;
    }

    if ( ( pos + 1 ) == count ) {

        head = d_insert_last ( head , data );

        return head;

    }

    //ptr is made to move till the pos 
    while  ( pos -- ) {

        ptr  = ptr -> next  ;

    } 

    new -> next = ptr -> next;

    ptr -> next -> prev = new;

    new -> prev = ptr;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added after the POSITION of the linked list \n\n");

    return head;
}



dlist *d_insert_before_num ( dlist *head, int data, int num )
{
    dlist *ptr = head;

    dlist *new = d_create_node ( data );

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

            new -> next = ptr -> next;

            ptr -> next -> prev = new;

            new -> prev = ptr;

            ptr -> next = new;

            head -> data = ( head -> data ) + 1;

            printf ("\nData is added before the NUMBER of the linked list \n\n");

            return head;
        }

        ptr = ptr -> next;
    }

    //if first nodes having the data

    new -> next = head -> next;

    head -> next -> prev = new;

    new -> prev = head;

    head -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added before the NUMBER of the linked list \n\n");

    return head;
}


dlist *d_insert_after_num ( dlist *head, int data, int num )
{
    dlist *ptr = head;

    dlist *new = d_create_node ( data );

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

    if ( ptr -> next == NULL ) {

        head = d_insert_last ( head , data );

        return head;

    }



    new -> next = ptr -> next;

    ptr -> next -> prev = new;

    new -> prev = ptr;

    ptr -> next = new;

    head -> data = ( head -> data ) + 1;

    printf ("\nData is added after the NUMBER of the linked list \n\n");

    return head;
}


dlist *d_insert_middle ( dlist *head, int data )
{

    int count = head -> data;

    if ( NULL == head -> next ) {

        printf ("\n<--------List is Empty-------->\n");
        return head;

    }

    if ( head -> data >= 2) {

        head = d_insert_at_pos ( head, data, ( count / 2 ));

    } else {

        //middle node cannot be added if there 1 node or less
        printf ("\nMiddle node cannot be added\n");

    }

    return head;

}


dlist *d_insert_penultimate ( dlist *head, int data )
{

    dlist *ptr = head;

    dlist *new = d_create_node ( data );

    if ( NULL == head -> next ) {

        printf ("\n<--------List is Empty-------->\n");
        return head;

    }

    if ( NULL != ptr -> next ) {

        ptr = ptr -> next;
    }


    new -> next = ptr;

    new -> prev = ptr -> prev -> next;

    ptr -> prev -> next = new;

    ptr -> prev = new;

    head -> data += 1;

    return head;

}




    





























dlist *d_create_node ( int data ) 
{

    dlist *new = ( dlist * ) malloc ( sizeof ( dlist ));

    new -> data = data;

    new -> next = NULL;

    new -> prev = NULL;

    return new;
}









