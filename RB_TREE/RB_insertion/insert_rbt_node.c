
#include "header.h"

void insert_rbt_node (void)
{
	RB_TREE *temp_node, *temp_ptr, *parent;			// ****** pointers used to insert the node in proper position ****** //

	parent      = temp_dummy;				// *****  used for first time inserting the node in function   ***** //
	temp_ptr    = root;

	while( temp_ptr != temp_dummy ){			// ******  traversing till dummy node  ****** // 

		parent = temp_ptr;			

		if ( num  <  temp_ptr -> data ){		// ******  left traversal ****** //	
			temp_ptr = temp_ptr -> left;
		}

		else if ( num > temp_ptr -> data ){
			temp_ptr = temp_ptr -> right;		// ******  right traversal ***** //
		}

		else{		
			printf ("duplicate node not inserted \n");
			return;					// ****** try to insert duplicate node return to main ***** //
		}
	}
	temp_node = create_rb_tree_node (parent);		// ****** creating new node for inserting data ****** // 

	if (parent == temp_dummy){				// ****** making first node as a root node ****** //
		root = temp_node;
	}

	else if (temp_node -> data <  parent -> data ){		// ****** insrting new node in left side of the tree ****** //
		parent -> left = temp_node;
	}

	else{
		parent -> right = temp_node;			// ****** insrting new node in right side of the tree ****** //
	}

	balance_tree (temp_node);				// ****** function to  balanc the tree ****** //

	if( root->color == RED ){ 				// ****** root color always black ****** //
		root->color = BLACK;
	}

}

