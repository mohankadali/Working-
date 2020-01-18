#include"header.h"

void rotate_right (RB_TREE *ptr)
{
	RB_TREE *pptr;

	pptr      = ptr  -> left;
	ptr->left = pptr -> right;

	if(pptr -> right != temp_dummy ){
		pptr -> right -> parent = ptr;
	}

	pptr -> parent = ptr -> parent;

	if(ptr -> parent == temp_dummy ){
		root = pptr;
	}
	else if( ptr == ptr -> parent -> right ){
		ptr -> parent -> right = pptr;
	}
	else{
		ptr -> parent -> left = pptr;
	}
	pptr -> right  = ptr;
	ptr  -> parent = pptr;
}
