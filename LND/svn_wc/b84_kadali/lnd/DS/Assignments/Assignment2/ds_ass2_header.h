#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>

//assignment1
#define SIZE 5
int searching ( void );
int linear_search ( int *arr, int num, int size );
int binary_search ( int *arr, int num, int size );

int * sorting ( int *, int );

//ass2
void sort ( void );
int *bubble_sort ( int *, int );
int *selection_sort ( int *, int );
int *insertion_sort ( int *, int );
int *merg_sort ( int *,int *, int, int );
int *merg ( int *, int *, int, int, int );

int *quick_sort ( int *, int, int );
void swap ( int *, int, int );
void display ( int *,int );

//ass3
typedef struct trees
{
    int data;
    struct trees *left;
    struct trees *right;
}tree;

void Btree ( void );
tree *insert_tree ( tree *, int );
tree *create_node ( int );

void display_tree ( tree * );
void pre_order ( tree * );
void post_order ( tree * );
void in_order ( tree * );

int search_tree ( tree *, int );

void level_order ( tree * );
int height_tree ( tree * );
int print_level ( tree * , int );

tree *delete_tree ( tree *, int );
tree *root_delete ( tree *);

#endif
