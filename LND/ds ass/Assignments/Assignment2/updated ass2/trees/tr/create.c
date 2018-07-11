#include"header.h"

struct node * create_node( struct node * root ,int data)
{ 
struct node  * nu;  //creating a struct pointer variable

nu = (struct node *) malloc (sizeof(struct node));//alloacating memory

nu -> info = data;     //adding data value into node
nu -> l_link = NULL;   //making the leaf links to NULL
nu -> r_link = NULL;
//root = temp;        //root pointing to the new node

return nu;	//returning the node

}

