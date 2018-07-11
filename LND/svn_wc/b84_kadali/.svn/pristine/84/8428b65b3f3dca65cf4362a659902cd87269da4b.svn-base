
#include <stdio.h>
#include "ds_ass1_header.h"


void a6 ( void )
{
    int opt;

    int main_opt;

    int data;

    int pos;

    int num;

    dlist *head_node = ( dlist *) calloc ( 1, sizeof ( dlist ));

    while ( 1 ) {

        printf ("\nEnter : \n\n1: INSERTION\n2: DELETION\n3: DISPLAY\n4: EXIT\n\n");
        scanf ("%d", &main_opt);



        if ( main_opt == 1 ) { 

            printf ("\nEnter the options for INSERTING :\n \n1:At beginning\n2:At last\n3:At position\n4:Before position\n5:After position\n6:Before number\n7:After number\n8:At middle\n9:At penultimate\n10:Exit\n\n");
            scanf ("%d", &opt );

            switch ( opt ) 
            {
                case 1: 
                    printf ("\n<--------Insert Beginning---------> \n\n");

                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );

                    head_node = d_insert_first ( head_node, data );

                    break;

                case 2:
                    printf ("\n<--------Insert Last---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );

                    head_node = d_insert_last ( head_node, data );

                    break;

                case 3:
                    printf ("\n<--------Insert at Position---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );
                    printf ("\nEnter the position to add the node \n");
                    scanf ("%d", &pos );

                    head_node = d_insert_at_pos ( head_node, data, pos );

                    break;

                case 4:
                    printf ("\n<--------Insert before Position---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );
                    printf ("\nEnter the position of the node \n");
                    scanf ("%d", &pos );

                    head_node = d_insert_before_pos ( head_node, data, pos );

                    break;

                case 5:
                    printf ("\n<--------Insert after Position---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );
                    printf ("\nEnter the position of the node \n");
                    scanf ("%d", &pos );

                    head_node = d_insert_after_pos ( head_node, data, pos );

                    break;

                case 6:
                    printf ("\n<--------Insert before data---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );
                    printf ("\nEnter the data of the node \n");
                    scanf ("%d", &num );

                    head_node = d_insert_before_num ( head_node, data, num );

                    break;

                case 7:
                    printf ("\n<--------Insert after data---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );
                    printf ("\nEnter the data of the node \n");
                    scanf ("%d", &num );

                    head_node = d_insert_after_num ( head_node, data, num );

                    break;

                case 8:
                    printf ("\n<--------Insert middle---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );

                    head_node = d_insert_middle ( head_node, data );

                    printf ("\nMiddle node has been added\n");

                    break;

                case 9:
                    printf ("\n<--------Insert penultimate---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );

                    head_node = d_insert_penultimate ( head_node, data );

                    printf ("\nPenultimate node has been added\n");
                    break;

                case 10:
                    return;
                    break;

                default :
                    printf ("\nEnter a valid option \n");
                    break;
            }
        }


        if ( main_opt == 2 ) { 

            printf ("\nEnter the options for DELETING :\n \n1:At beginning\n2:At last\n3:At position\n4:Before position\n5:After position\n6:Before number\n7:After number\n8:At middle\n9:At penultimate\n\n");
            scanf ("%d", &opt );

            switch ( opt ) 
            {
                case 1: 
                    printf ("\n<--------Delete Beginning---------> \n\n");

                    head_node = d_delete_first ( head_node );

                    break;
                    
                       case 2:
                       printf ("\n<--------Delete Last---------> \n\n");

                       head_node = d_delete_last ( head_node );

                       break;

                       case 3:
                       printf ("\n<--------Delete at Position---------> \n\n");
                       printf ("\nEnter the position to delete the node \n");
                       scanf ("%d", &pos );

                       head_node = d_delete_at_pos ( head_node, pos );

                       break;

                       case 4:
                       printf ("\n<--------Delete before Position---------> \n\n");
                       printf ("\nEnter the position of the node \n");
                       scanf ("%d", &pos );

                       head_node = d_delete_before_pos ( head_node, pos );

                       break;

                       case 5:
                       printf ("\n<--------Delete after Position---------> \n\n");
                       printf ("\nEnter the position of the node \n");
                       scanf ("%d", &pos );

                       head_node = d_delete_after_pos ( head_node, pos );

                       break;

                       case 6:
                       printf ("\n<--------Delete before data---------> \n\n");
                       printf ("\nEnter the data of the node \n");
                       scanf ("%d", &num );

                       head_node = d_delete_before_num ( head_node, num );

                       break;

                       case 7:
                       printf ("\n<--------Delete after data---------> \n\n");
                       printf ("\nEnter the data of the node \n");
                       scanf ("%d", &num );

                       head_node = d_delete_after_num ( head_node, num );

                       break;

                       case 8:
                       printf ("\n<--------Delete middle---------> \n\n");

                       head_node = d_delete_middle ( head_node );

                       break;

                       case 9:
                       printf ("\n<--------Delete penultimate---------> \n\n");

                       head_node = d_delete_penultimate ( head_node );

                       break;
                       

                              default :
                    printf ("\nEnter a valid option \n");
                    break;
            }

        }

        if ( main_opt == 3 ) {

            display_dlist ( head_node );

        }

        if ( main_opt == 4 ) {

            return;

        }
    }
}
































