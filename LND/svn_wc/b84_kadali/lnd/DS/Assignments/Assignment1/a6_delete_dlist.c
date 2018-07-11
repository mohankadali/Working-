
#include <stdio.h>
#include "ds_ass1_header.h"

dlist * d_delete_first ( dlist *head  )
{
    dlist *ptr = head;
    //to d_delete a head node
    if ( head -> next == NULL ) {

        printf ("\n<-------List is Empty------->\n\n");

        return head;

    } else {

        ptr = ptr -> next;

    }
    //to d_delete first node

    head -> next = ptr -> next ;

    ptr -> next -> prev = head;

    free ( ptr );

    head -> data = ( head -> data ) - 1 ;

    printf ("\nNode is deleted at the BEGINNING of linked list \n\n");

    return head;
}


dlist * d_delete_last ( dlist *head  )
{
    //pointer to traverse through the list
    dlist *ptr = head;

    dlist *ptr1 = head;

    if ( head -> next  == NULL ) {

        printf ("\n<-------List is Empty------->\n\n");

        return head;
    }

    //while loop will break when the node is pointing to NULL 
    while ( ptr->next != NULL ) {

        if ( ptr -> next -> next == NULL ) {

            ptr1 = ptr -> next;

            ptr -> next = NULL;

            free ( ptr1 );

            printf ("\nNode is deleted at the END of the linked list \n\n");

            head -> data = ( head -> data ) - 1 ;

            return head;

        }

        ptr = ptr->next;
    }

    return head;
}



dlist * d_delete_at_pos ( dlist *head , int pos )
{

    int count = head -> data;

    dlist *ptr = head;

    dlist *ptr1 = head;

    //if will check if there is any node present
    if ( head -> next == NULL ) {
        printf ("\n<-------List is empty----->\n");
    }

    if ( pos >= count ) {

        printf ("\n<--------Node cannot be deleted at POSITION---------> \n");

        return head;
    }

    while  (  pos -- ) {

        ptr  = ptr -> next  ;
    } 

    ptr1 = ptr -> next;

    //node to be deleted is the last node
    if ( ptr1 -> next == NULL ) {

        ptr -> next = NULL;

        head -> data -= 1;

        free ( ptr1 );

        printf ("\nNode is deleted at the POSITION of the linked list \n\n");

        return head;
    }

    ptr  -> next = ptr1 -> next;

    ptr1 -> next -> prev = ptr;

    free ( ptr1 );

    head -> data = ( head -> data ) - 1 ;

    printf ("\nNode is deleted at the POSITION of the linked list \n\n");

    return head;
}

dlist *d_delete_before_pos ( dlist *head , int pos )
{
    int count = head -> data;

    dlist *ptr = head;

    dlist *ptr1 = head;

   //if will check if there is any node present
    if ( head -> next != NULL ) {

        //if there are nodes more than 1 and if you want to d_delete the node before pos 0 
        if ( pos == 0 ) {

            printf ("\n<-------Node cannot be deleted before the given POSITION------->\n");
            return head;
        }

    } else if ( head -> next == NULL ) {

        printf ("\n<-------List is empty----->\n");

        return head;
    }

    if ( pos  >  count ) {

        printf ("\n<--------Node cannot be deleted before specified POSITION---------> \n");

        return head;
    }

    while  ( -- pos ) {

        ptr  = ptr -> next  ;
    } 

    ptr1 = ptr -> prev;

    if ( ptr -> next == NULL ) {

        ptr1 -> next = NULL;

        free ( ptr );

    head -> data = ( head -> data ) - 1;

    printf ("\nNode is deleted before the POSITION of the linked list \n\n");

    return head;
    }


    ptr1 -> next = ptr -> next;

    ptr -> next -> prev = ptr1;

    free ( ptr );

    head -> data = ( head -> data ) - 1;

    printf ("\nNode is deleted before the POSITION of the linked list \n\n");

    return head;
}



dlist *d_delete_after_pos ( dlist *head , int pos )
{


    int count = head -> data;

    dlist *ptr = head;

    dlist *ptr1 = head;
    //error condition when position is an invalid pos 
    //if will check if there is any node present
    if ( head -> next != NULL ) {

        //we have to move the pointer ptr to the first node which is after the DUMMY header node so point it to next node
        ptr = ptr -> next;

    } else {

        printf ("\n<-------List is empty----->\n");

        return head;
    }

    if ( ( pos + 1 ) >=  count ) {

        printf ("\n<--------Node cannot be deleted after the POSITION---------> \n");
        return head;
    }

    //ptr is made to move till the pos 
    while  ( pos -- ) {

        ptr  = ptr -> next  ;

    } 

    ptr1 = ptr -> next;
   //node to be deleted is the last node
    if ( ptr1 -> next == NULL ) {

        ptr -> next = NULL;

        head -> data -= 1;

        free ( ptr1 );

        printf ("\nNode is deleted at the POSITION of the linked list \n\n");

        return head;
    }

    ptr -> next = ptr1 -> next;

    ptr1 -> next -> prev = ptr;

    free ( ptr );

    head -> data = ( head -> data ) - 1;

    printf ("\nNode is deleted after the POSITION of the linked list \n\n");

    return head;
}

dlist *d_delete_before_num ( dlist *head , int num )
{
    dlist *ptr = head;
    dlist *prev =  head;

    if ( head -> next == NULL ) {

        printf ("\n<---------List is Empty-----------> \n");

        return head;

    } else {

        ptr = ptr -> next ;
    }

    while ( ptr -> data != num) {

        if ( ptr -> next == NULL ) {

            printf ("\n<-----Data not present---->\n");
            return head;
        }

        if ( ( ptr -> next -> data )  == num ) {

            prev -> next = ptr -> next ;

            ptr -> next -> prev = prev;

            free ( ptr );

            head -> data = ( head -> data ) - 1;

            printf ("\nNode is deleted before the NUMBER of the linked list \n\n");

            return head;
        }

        ptr = ptr -> next;
        prev = prev -> next;
    }

    //if first nodes having the data

    printf ("\n<------Node cannot be deleted before the NUMBER-------> \n\n");

    return head;
}


dlist *d_delete_after_num ( dlist *head , int num )
{
    dlist *ptr = head;

    dlist *ptr1 = head;

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

        printf ("\n<-----There is no Node to be deleted----->\n");

        return head;

    }

   ptr1 = ptr -> next;
   //node to be deleted is the last node
    if ( ptr1 -> next == NULL ) {

        ptr -> next = NULL;

        head -> data -= 1;

        free ( ptr1 );

        printf ("\nNode is deleted after the NUMBER of the linked list \n\n");

        return head;
    }

    ptr -> next = ptr1 -> next;

    ptr1 -> next -> prev = ptr;

    free ( ptr1 );

    head -> data = ( head -> data ) - 1;

    printf ("\nNode is deleted after the NUMBER of the linked list \n\n");

    return head;
}



dlist *d_delete_middle ( dlist *head  )
{


    dlist *ptr = head;

    int count = head -> data;

    if ( head -> next == NULL ) {

        printf ("\n<-----List is empty----->\n");
        return head;

    } else {

        ptr = ptr -> next;

        //if there only one node
        if ( ptr -> next == NULL ) {


        printf ("\nThere is no middle node\n");

        return head;
        }
    }

    if ( ptr -> next != NULL ) {

        ptr = ptr -> next;

        //if there is only 2 node
        if ( ptr -> next == NULL ) {


        printf ("\nThere is no middle node\n");

        return head;
        }

    }

    if ( count % 2 == 0 ) {

        head = d_delete_at_pos ( head, ( count / 2 ) - 1 ) ;

        printf ("\nMiddle node is deleted \n");

        return head;

    } else {

        head = d_delete_at_pos ( head, ( count / 2 ) ) ;

        printf ("\nMiddle node is deleted \n");

        return head;

    }

}


dlist *d_delete_penultimate ( dlist *head  )
{
    dlist *ptr = head;
    dlist *prev = head;

    if ( head -> next == NULL ) {

        printf ("\n<-------LIST IS EMPTY-------> \n");

        return head;

    } else { 

        ptr = ptr -> next;
    }

    while ( ptr -> next != NULL ) {

        if ( ptr -> next -> next == NULL ) {

            prev -> next = ptr -> next;

            ptr -> next -> prev = prev;

            head -> data = ( head -> data ) - 1;

            printf ("\nData is deleted at the PENULTIMATE of the linked list \n\n");

            return head;
        }

        prev = ptr;
        ptr = ptr -> next;

    }

    printf ("\n<-----No penultimate node------> \n");
    return head;
}


