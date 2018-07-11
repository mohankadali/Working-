#include <stdio.h>
#include "ds_ass2_header.h"

void Btree ( void )
{

    int opt;

    int data;

    int found;

    tree *root = NULL;

    while ( 1 )
    {

        printf ("\nEnter the option : \n1:Insert node\n2:Search\n3:Delete\n4:Display\n5:Exit\n\n");

        scanf ("%d", &opt );


        switch ( opt ) 
        {
            case 1:
                printf ("\n<------Insertion------> \n");

                printf ("\nEnter the data to insert \n");
                scanf ("%d", &data );

                root = insert_tree ( root, data );

                break;

            case 2:
                printf ("\n<------Search------> \n");

                printf ("\nEnter the data to search \n");
                scanf ("%d", &data );

                found = search_tree ( root, data );

                if ( found ) {

                    printf ("\nElement is present in the tree\n");

                } else {

                    printf ("\nElement not present\n");

                }

                break;

            case 3:
                printf ("\n<-------Delete------> \n");

                printf ("\nEnter the data to search \n");
                scanf ("%d", &data );

                root = delete_tree ( root, data );

                printf ("\nElement deleted\n \n");
                pre_order ( root );

                printf ("\n ");
                break;




            case 4:
                printf ("\n<------Display------> \n");
                display_tree ( root );
                break;

            case 5:
                return;

            default:
                printf ("\nInvalid option \n\n");
                break;

        }
    }
}
