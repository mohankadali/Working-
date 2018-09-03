
// ******    Header guard    ****** //

#ifndef __HEADER_H
#define __HEADER_H

// ******    header files    ****** //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ******    MACROS   ****** //

#define MAX 100
#define REDD     "\x1b[31m"
#define GREEN    "\x1b[32m"
#define RESET    "\x1b[0m"

// ******   RBT structure declaration    ****** //

typedef struct  st {
	int data;
	struct st *left;
	struct st *right;
	struct st *parent;
	enum { BLACK , RED } color;
}RB_TREE;

// *******    variables declarations    ******** //

int choice; 
int num;

// ******* pointers declarations    ******** //

char *p ;
RB_TREE *temp_dummy;
RB_TREE *root;
RB_TREE *create_node;

// ******   RBT Function declarations   ****** //

RB_TREE *rbt_preorder_traversal ( RB_TREE* );
RB_TREE *dummy_rbt_node ( void );
RB_TREE* create_rb_tree_node (RB_TREE*);

void insert_rbt_node (void);
void balance_tree ( RB_TREE* );
void rotate_left (RB_TREE*);
void rotate_right (RB_TREE*);

#endif

