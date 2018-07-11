
#include <stdio.h>
#include "ds_ass1_header.h"


void a8 ( void )
{
    int opt;

    int main_opt;

    int data;

    dlist *head_node = NULL;

    while ( 1 ) {

        printf ("\nEnter : \n\n1: INSERTION\n2: DELETION\n3: DISPLAY\n4: EXIT\n\n");
        scanf ("%d", &main_opt);



        if ( main_opt == 1 ) { 

            printf ("\nEnter the options for INSERTING :\n \n1:At beginning\n2:At last\n3:Exit\n\n");
            scanf ("%d", &opt );

            switch ( opt ) 
            {
                case 1: 
                    printf ("\n<--------Insert Beginning---------> \n\n");

                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );

                    head_node = d_cir_insert_first ( &head_node, data );

                    break;

                case 2:
                    printf ("\n<--------Insert Last---------> \n\n");
                    printf ("\nEnter the data to be inserted \n");
                    scanf ("%d", &data );

                    head_node = d_cir_insert_last ( &head_node, data );

                    break;

                case 3:
                    return;
                    break;

                default :
                    printf ("\nEnter a valid option \n");
                    break;
            }
        }

/*
        if ( main_opt == 2 ) { 

            printf ("\nEnter the options for DELETING :\n \n1:At beginning\n2:At last\n3:Exit\n\n");
            scanf ("%d", &opt );

            switch ( opt ) 
            {
                case 1: 
                    printf ("\n<--------Delete Beginning---------> \n\n");

                    head_node = d_cir_delete_first ( &head_node );

                    break;

                case 2:
                    printf ("\n<--------Delete Last---------> \n\n");

                    head_node = d_cir_delete_last ( &head_node );

                    break;

                case 3:
                    return;
                    break;

                default :
                    printf ("\nEnter a valid option \n");
                    break;
            }

        }
*/
        if ( main_opt == 3 ) {

            d_cir_display_dlist ( head_node );

        }

        if ( main_opt == 4 ) {

            return;

        }
    }
}
































