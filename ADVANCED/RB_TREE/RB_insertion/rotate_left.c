#include "header.h"
void rotate_left (RB_TREE *ptr)
{
	RB_TREE *pptr;

	pptr       = ptr  -> right;    
	ptr->right = pptr -> left;

	if (pptr -> left != temp_dummy){
		pptr -> left -> parent = ptr;
	}
	pptr -> parent = ptr -> parent;

	if(ptr -> parent == temp_dummy ){
		root = pptr;
	}
	else if( ptr == ptr -> parent -> left ){
		ptr -> parent -> left = pptr;
	}
	else{
		ptr -> parent -> right = pptr;
	}	
	pptr -> left   = ptr;
	ptr  -> parent = pptr;
}

