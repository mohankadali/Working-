#include "header.h"

RB_TREE *rbt_preorder_traversal (RB_TREE *root)			// ******   preorder traversal function definition ****** //
{

	if (root) {
		if ((root -> data) != -1){
			if (root -> color == RED ){
		//		printf ("%d-%d  ", root -> data, root -> color);

				printf (REDD"%d  ",root ->data );
				printf(RESET);
			}			
			else{
		//		printf ("%d-%d  ", root -> data, root -> color);

				printf ("%d  ",root ->data );
			}
		}
		rbt_preorder_traversal (root -> left);		// ******   recursive calling for left nodes *******    // 
		rbt_preorder_traversal (root -> right);		// ******   recursive calling for right nodes *******   //
	}

	return root;
}
