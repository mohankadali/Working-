#include<stdio.h> 
#include<stdlib.h>
typedef struct st
{
    int data;
    struct st *left,*right;
}BST;

BST *new (int item)
{

    BST *temp = (BST*)malloc(sizeof(BST));
    temp -> data = item;
    temp ->left = temp->right  = NULL;
    return temp;
}

BST *insert ( BST *node, int item )
{
    if(node == 0 )
        return new(item);
    else if(item < node -> data )
        node->left = insert (node->left , item);
    else if(item > node -> data )
        node->right = insert (node->right , item);

    return node;
}    

void inorder(BST *root)
{
    if (root != NULL)
    {
        inorder(root -> left);
        printf("%d \n", root -> data);
        inorder(root -> right);
    }
}


int main()
{
    BST *root = NULL;
    root = insert(root, 50);
    insert (root, 30);
    insert (root, 20);
    insert (root, 40);
    insert (root, 70);
    insert (root, 60);
    insert (root, 80);

    inorder(root);
    return 0;
}

