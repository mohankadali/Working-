#include <stdio.h>

#include "ds_ass2_header.h"

int search_tree ( tree *root , int data )
{

    int ret;

    if ( root -> data == data ) {

        return 1 ;

    }
    if ( root != NULL ) {

        if ( data < root -> data ) {

            if ( NULL != root -> left ) {

                ret = search_tree ( root -> left, data );

            } else {

                return 0;
            }

        } else if ( data > root -> data ) {

            if ( NULL != root -> right ) {

                ret = search_tree ( root -> right, data );

            } else {

                return 0;
            }
        }

    } else {

        return 0;

    }

    return ret;
}






