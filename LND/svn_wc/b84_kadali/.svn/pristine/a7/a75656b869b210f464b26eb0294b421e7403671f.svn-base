
#include <stdio.h>
#include "ds_ass1_header.h"

slist * delete_first ( slist *head  )
{
    //to create a head node
    if ( head -> next == NULL ) {

        printf ("\n<-------List is Empty------->\n\n");

        return head;

    }
    //to create rest of the node

    head -> next = head -> next -> next ;

    head -> data = ( head -> data ) - 1 ;

    printf ("\nNode is deleted at the BEGINNING of linked list \n\n");

    return head;
}


slist * delete_last ( slist *head  )
{
    //pointer to traverse through the list
    slist *ptr = head;

    if ( head -> next  == NULL ) {

        printf ("\n<-------List is Empty------->\n\n");

        return head;
    }

    //while loop will break when the node is pointing to NULL 
    while ( ptr->next != NULL ) {

        if ( ptr -> next -> next == NULL ) {

            ptr -> next = NULL;

            printf ("\nNode is deleted at the END of the linked list \n\n");

            head -> data = ( head -> data ) - 1 ;

            return head;

        }

        ptr = ptr->next;
    }

    return head;
}



slist * delete_at_pos ( slist *head , int pos )
{

    int count = 0;

    slist *ptr = head;

    //error condition when position is an invalid pos 
    //count will have the count of number of nodes present
    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;
        count ++;

    }
    //pointer ptr is made to point back to the head node
    ptr = head;

    //if will check if there is any node present
    if ( head -> next != NULL ) {
        //we have to move the pointer ptr to the first node which is after the DUMMY header node so point it to next node
        ptr = ptr -> next;

        //if there are nodes more than 1 and if you want to delete the node at pos 0 
        if ( pos == 0 ) {

            head -> next = head -> next -> next;

            head -> data = ( head -> data ) - 1 ;

            printf ("\nNode is deleted at the POSITION of the linked list \n\n");

            return head;
        }

    } else {

        printf ("\n<-------Node cannot be deleted at the position you specified------------> \n\n<-------List is empty----->\n");
    }

    if ( pos >= count ) {

        printf ("\n<--------Node cannot be deleted at POSITION---------> \n");

        return head;
    }

    while  ( -- pos ) {

        ptr  = ptr -> next  ;
    } 

    ptr  -> next = ptr -> next -> next;

    head -> data = ( head -> data ) - 1 ;

    printf ("\nNode is deleted at the POSITION of the linked list \n\n");

    return head;
}


slist *delete_before_pos ( slist *head , int pos )
{
    int count = 0;

    slist *ptr = head;

    //error condition when position is an invalid pos 
    //count will have the count of number of nodes present
    while ( ptr -> next != NULL ) {

        ptr = ptr -> next;

        count ++;
    }

    //pointer ptr is made to point back to the head node
    ptr = head;

    //if will check if there is any node present
    if ( head -> next != NULL ) {

        //if there are nodes more than 1 and if you want to delete the node before pos 0 
        if ( pos == 0 ) {

            printf ("\n<-------Node cannot be deleted before the given POSITION------->\n");
            return head;
        }

    } else {

        printf ("\n<-------Node cannot be deleted before the position you specified------------> \n\n<-------List is empty----->\n");

        return head;
    }

    if ( ( pos + 1 ) >=  count ) {

        printf ("\n<--------Node cannot be deleted before specified POSITION---------> \n");

        return head;
    }

    while  ( -- pos ) {

        ptr  = ptr -> next  ;
    } 

    ptr -> next = ptr -> next -> next;

    head -> data = ( head -> data ) - 1;

    printf ("\nNode is deleted before the POSITION of the linked list \n\n");

    return head;
}


slist *delete_after_pos ( slist *head , int pos )
{


    int count = 0;

    slist *ptr = head;

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

        printf ("\n<-------Node cannot be deleted after the position you specified------------> \n\n<-------List is empty----->\n");

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

    ptr -> next = ptr -> next -> next;

    head -> data = ( head -> data ) - 1;

    printf ("\nNode is deleted after the POSITION of the linked list \n\n");

    return head;
}


slist *delete_before_num ( slist *head , int num )
{
    slist *ptr = head;
    slist *prev =  head;

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


slist *delete_after_num ( slist *head , int num )
{
    slist *ptr = head;

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

    ptr -> next = NULL;

    head -> data = ( head -> data ) - 1;

    printf ("\nData is deleted after the NUMBER of the linked list \n\n");

    return head;
}


slist *delete_middle ( slist *head  )
{


    slist *ptr = head;

    int count = 0;

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

    count = head -> data ;

    if ( count % 2 == 0 ) {

        head = delete_at_pos ( head, ( count / 2 ) - 1 ) ;

        printf ("\nMiddle node is deleted \n");

        return head;

    } else {

        head = delete_at_pos ( head, ( count / 2 ) ) ;

        printf ("\nMiddle node is deleted \n");

        return head;

    }

}


slist *delete_penultimate ( slist *head  )
{
    slist *ptr = head;
    slist *prev = head;

    if ( head -> next == NULL ) {

        printf ("\n<-------LIST IS EMPTY-------> \n");

        return head;

    } else { 

        ptr = ptr -> next;
    }

    while ( ptr -> next != NULL ) {

        if ( ptr -> next -> next == NULL ) {

            prev -> next = ptr -> next;

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


