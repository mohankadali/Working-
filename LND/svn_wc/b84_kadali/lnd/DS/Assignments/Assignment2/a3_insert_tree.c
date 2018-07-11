#include <stdio.h>

#include "ds_ass2_header.h"

tree *insert_tree ( tree *root, int data )
{

    if ( root == NULL ) {

        root = create_node ( data );

        printf ("\nroot added \n");

        

    } else {

        if ( data > ( root -> data ) ) {

            printf ("\nright add \n");

            root -> right = insert_tree ( root -> right , data  );

        } else if( data < (root -> data) ) {

            printf ("\nleft add \n");

            root -> left = insert_tree ( root -> left , data  );

        }
    }

    return root;
}


tree *create_node ( int data )
{
    tree *new = ( tree * ) malloc ( sizeof ( tree ) );

    new -> data = data;

    new -> right = NULL;

    new -> left = NULL;

    return new;
}









