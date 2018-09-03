#include "header.h"


RB_TREE* create_rb_tree_node(RB_TREE *parent)
{
	create_node  = (RB_TREE *) malloc (sizeof (RB_TREE));
	create_node -> data   = num;
	create_node -> left   = temp_dummy;
	create_node -> right  = temp_dummy;
	create_node -> color  = RED;
	create_node -> parent = parent;

	return create_node;
}

