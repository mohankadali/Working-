
#include<stdio.h>
#include"header.h"
#include<stdlib.h>
struct node * traversal_left_side(struct node * root)
{
    if(root==NULL)
        return root;
   while(root->l_link != NULL)
    {
      root=root->l_link;
       }

//   printf("\nmin : %d\n",root->info);
   return root;
}


