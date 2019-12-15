#include <stdio.h>
#include <stdlib.h>

struct node
 {
   int info;
   struct node  * l_link;
   struct node  * r_link;
 };

struct node * insert(struct node *,int);// insertion function 
struct node * create_node(struct node*,int);//create node
struct node * traversal_left_side(struct node *);//traversal and finding minimum value
       


