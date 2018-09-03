#include"header.h"

RB_TREE* dummy_rbt_node (void)		  			// *******   inserting the dummy nodes    ******** //
{
	temp_dummy = malloc (sizeof (RB_TREE));			// *******    allocating memory dynamically ******* //  
	if (temp_dummy == NULL){
		exit(EXIT_FAILURE);
	}

	temp_dummy -> data = 0;					
	temp_dummy -> color = BLACK;				// *******    dummy node  should be black node  ******** //
	return temp_dummy ; 					
}

