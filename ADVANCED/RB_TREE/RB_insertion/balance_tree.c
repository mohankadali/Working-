

#include "header.h"


void balance_tree (RB_TREE *cur_node )
{
	RB_TREE *uncle, *parent, *grandParent;					// ******* required pointers to balace the tree ******* //	

	while ( cur_node -> parent -> color == RED ){	                	// ******* checking for double red problem ******* //	

		parent      = cur_node -> parent;				// ******* updating parent pointer ******* //
		grandParent = parent -> parent;					// ******* updating grand parent pointer ******* //

		if ( parent == grandParent -> left ){				// ****** checking for left node  ******* //
			uncle = grandParent -> right;				// ****** updating the right uncle pointer ****** //

			if (uncle -> color == RED ){                   	        // ****** case L_1 ****** //
				parent      -> color = BLACK;
				uncle       -> color = BLACK;
				grandParent -> color = RED;
				cur_node             = grandParent;
			}
			else{
				if( cur_node == parent -> right){            	// ******* case L_2a ******  //
		
					rotate_left (parent);			// ******* calling the left rotate function ****** //	
			
					cur_node = parent;
					parent   = cur_node -> parent;
				}
				
				rotate_right (grandParent);			// ****** calling the right rotate function ****** //
				
				parent      -> color = BLACK;      		// ******  case L_2b ****** //
				grandParent -> color = RED;
			}
		}
		else{
			if(parent == grandParent -> right ){			// ******* checking for right node ******* //
				uncle = grandParent -> left;			// ******* updating left uncle pointer ******* //	

				if(uncle -> color == RED ){  		        // ******* case R_1 ******* //
					parent      -> color = BLACK;
					uncle       -> color = BLACK;
					grandParent -> color = RED;
					cur_node             = grandParent;
				}
				else{
					if( cur_node == parent->left){           // *******  case R_2a ******* //
						
						rotate_right (parent);		 // *******  calling right rotate function ****** //	
						
						cur_node  = parent;
						parent    = cur_node -> parent;
					}

					rotate_left (grandParent);		 // ****** calling left rotate function ****** //	

					parent      -> color = BLACK;            // ******* Case R_2b ******* //
					grandParent -> color = RED;
				}
			}
		}
	}
}
