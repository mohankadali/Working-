#include <stdio.h>

#include "ds_ass2_header.h"

tree *delete_tree ( tree *root, int data )
{

    tree *ptr = root;

    tree *ptr1 = NULL;

    if ( root == NULL ) {

        return NULL;

    }

    while ( ptr != NULL ) {

        //if we have to delete the main root node
        if ( root -> data == data ) {

            root = root_delete ( root );

            return root;

        }

        if ( ptr -> data == data ) {

            //CASE 1 : ptr has no childs
            
            if ( ( ptr -> right == NULL ) && ( ptr -> left == NULL ) ) {

                
                    //check to which side the node to be deleted is left/right of its parent node
                    if ( ptr1 -> left == ptr ) {

                        ptr1 -> left = NULL;

                    } else if ( ptr1 -> right == ptr ) {

                        ptr1 -> right = NULL;

                    }

                    free ( ptr );

                    return root;

            }

            //CASE 2 : ptr has no childs
            
            if ( ( ptr -> right != NULL ) && ( ptr -> left != NULL ) ) {

                ptr = root_delete ( ptr );

                return  root;

            }


            //CASE 3 : if ptr node has only left or right link

            if ( ( ptr -> right == NULL ) || ( ptr -> left == NULL ) ) {

                //check whether right side is null
                if ( ptr -> right == NULL ) {

                    //check to which side the node to be deleted is left/right of its parent node
                    if ( ptr1 -> left == ptr ) {

                        ptr1 -> left = ptr -> left;

                    } else {

                        ptr1 -> right = ptr -> left;
                    }
                } else if ( ptr -> left == NULL ) {

                    //check to which side the node to be deleted is left/right
                    if ( ptr1 -> left == ptr ) {

                        ptr1 -> left = ptr -> right;

                    } else {

                        ptr1 -> right = ptr -> right;
                    }
                } 

                free ( ptr );

                return root;
            }

        }

        if ( ptr -> data < data ) {

            ptr1 = ptr;

            ptr = ptr -> right; 
            continue;

        } else if ( ptr -> data > data ) {

            ptr1 = ptr;

            ptr = ptr -> left;
            continue;

        }

    }
    return root;
}



tree *root_delete ( tree *root )
{

    tree *ptr = root;

    tree *ptr1 = NULL;

    //check if there is right node and left node
    if ( root -> right != NULL ) {

        ptr = ptr -> right;

        //if there is only one right node with no child to the root
        if ( ( ptr -> left == NULL ) && ( ptr -> right == NULL ) ) {

            root -> data = ptr -> data;

            root -> right = NULL;

            free ( ptr );

            return root;
        }

            

        //traverse till you get the left node from the first right node
        while ( ptr -> left != NULL ) {

            ptr1 = ptr;

            ptr = ptr -> left;

        } 

        root -> data = ptr -> data;

        ptr1 -> left = NULL;

        free ( ptr );

        return root;

    } else if ( root -> left != NULL ) {

        ptr = ptr -> left;

        //if there is only one right node with no child to the root
        if ( ( ptr -> left == NULL ) && ( ptr -> right == NULL ) ) {

            root -> data = ptr -> data;

            root -> left = NULL;

            free ( ptr );

            return root;
        }

         
        //traverse till you get the left node from the first right node
        while ( ptr -> right != NULL ) {

            ptr1 = ptr;

            ptr = ptr -> right;

        }

        root -> data = ptr -> data;

        ptr1 -> right = NULL;

        free ( ptr );

        return root;

    }
    return root;
}








