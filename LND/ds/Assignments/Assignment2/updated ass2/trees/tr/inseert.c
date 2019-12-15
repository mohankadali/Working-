#include"header.h"

struct node *insert( struct node *root, int item)
{ 

    if(root == NULL) {
        root= create_node(root,item);
		return root;
	} else {    
    	if (item < root->info) {
       		root -> l_link = insert (root -> l_link, item);
   		} else { 
       		root->r_link= insert(root->r_link,item);
    	}   
	return root;
	}

}



