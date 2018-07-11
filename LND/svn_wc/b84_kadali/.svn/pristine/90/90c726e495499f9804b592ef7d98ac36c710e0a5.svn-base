#include <stdio.h>
#include "ds_ass2_header.h"

void display_tree ( tree *root )
{

    int opt;

    while ( 1 ) {

        printf ("\nEnter the option: \n1:pre order\n2:post order\n3:in order\n4:Level order\n5:Exit\n\n");
        scanf ("%d", &opt );


        switch ( opt )
        {
            case 1:
                printf ("\n<------PRE ORDER------>\n\n");
                pre_order ( root );
                printf ("\n");
                break;

            case 2:
                printf ("\n<------POST ORDER------>\n\n");
                post_order ( root );

                printf ("\n");
                break;

            case 3:
                printf ("\n<------IN ORDER------>\n\n");
                in_order ( root );
                printf ("\n");
                break;

            case 4:
                printf ("\n<------level ORDER------>\n\n");
                level_order ( root );
                printf ("\n");
                break;


            case 5:
                return;
                break;

            default:
                printf ("\nEnter a valid option \n");
                break;
        }
    }
    return;
}

void pre_order ( tree *root )
{

    if ( root != NULL ) {

        printf (" %d ", root -> data );

        //pre_order ( root );
        pre_order ( root -> left );
        pre_order ( root -> right );

    }
}


void post_order ( tree *root )
{

    if ( root != NULL ) { 


        //pre_order ( root );
        post_order ( root -> left );
        post_order ( root -> right );

        printf (" %d ", root -> data );

    }
}


void in_order ( tree *root )
{

    if ( root != NULL ) {

        in_order ( root -> left );

        printf (" %d ", root -> data );

        in_order ( root -> right );
    }
}

void level_order ( tree *root )
{

    int height = 0;

    int indx =0;

    height = height_tree ( root ) - 1;

    printf ("\nheight is : %d \n", height);

    printf ("\nElements are : \n\n");

    for ( indx = 1; indx <= height; indx ++ ) {

        print_level ( root , indx );

    }
}

int height_tree ( tree *root )
{

    int i =0;

    int j= 0;

    if ( NULL != root ) {


        i = height_tree ( root -> left );
        j = height_tree ( root -> right );

    }
    return i > j ? i + 1 : j + 1;
}
    
int print_level ( tree *root, int indx ) 
{
    if ( NULL == root ) {

        return 0;

    }

    if ( 1 == indx ) {

        printf (" %d  ", root -> data );
        return 0;
    }

    print_level ( root -> left , indx - 1 );
    print_level ( root -> right , indx - 1 );
    return 0;
}
    





