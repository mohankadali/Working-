#ifndef A1_H
#define A1_H

#include <stdio.h>
#include <stdlib.h>

//assignment 1

typedef struct s_list
{
    int data;
    struct s_list *next;

} slist;

#define MAX 5

int stack [ MAX ];

void a1 ( void );
void push ( int, int * );
void pop ( int * );
void display ( void );

//assignment2
int count;

void a2 ( void );
void push_list ( slist **, int );
void pop_list ( slist ** );
void display_list ( slist * );
slist *create_node ( int );  // this is also used in assignment 5 

//assignment3

int q [ MAX ];
void a3 ( void );
void en_q ( int, int *,int * );
void de_q ( int *,int * );
void display_q ( int *, int * );

//assignment4

int cir_q [ MAX ];
void a4 ( void );
void cir_en_q ( int, int *,int *, int * );
void cir_de_q ( int *,int *, int * );
void display_cir_q ( int , int  );
int is_empty ( int * );


//assignment5 single link list
void a5 ( void );
//slist* insert_first ( slist **, int );
slist* insert_first ( slist *, int );
slist* insert_last ( slist *, int );
slist *insert_at_pos ( slist *, int, int );
slist *insert_before_pos ( slist *, int, int );
slist *insert_after_pos ( slist *, int, int );
slist *insert_before_num ( slist *, int, int );
slist *insert_after_num ( slist *, int, int );
slist *insert_middle ( slist *, int );
slist *insert_penultimate ( slist *, int );
void display_slist( slist * );

//deletion
slist *delete_first ( slist * );
slist *delete_last ( slist * );
slist *delete_at_pos ( slist *, int );
slist *delete_before_pos ( slist *, int );
slist *delete_after_pos ( slist *, int );
slist *delete_before_num ( slist *, int );
slist *delete_after_num ( slist *, int );
slist *delete_middle ( slist * );
slist *delete_penultimate ( slist * );
#endif


typedef struct d_list
{
    int data;
    struct d_list *next;
    struct d_list *prev;

} dlist;


//assignment5 single link list
void a6 ( void );

dlist* d_insert_first ( dlist *, int );
dlist* d_insert_last ( dlist *, int );
dlist* d_insert_at_pos ( dlist *, int, int );
dlist* d_insert_before_pos ( dlist *, int, int );
dlist* d_insert_after_pos ( dlist *, int, int );
dlist* d_insert_before_num ( dlist *, int, int );
dlist* d_insert_after_num ( dlist *, int, int );
dlist* d_insert_middle ( dlist *, int );
dlist *d_insert_penultimate ( dlist *, int );

//deletion

dlist *d_delete_first ( dlist* );
dlist *d_delete_last ( dlist* );
dlist *d_delete_at_pos ( dlist*, int );
dlist *d_delete_before_pos ( dlist*, int );
dlist *d_delete_after_pos ( dlist*, int );
dlist *d_delete_before_num ( dlist*, int );
dlist *d_delete_after_num ( dlist*, int );
dlist *d_delete_middle ( dlist* );
dlist *d_delete_penultimate ( dlist*);

dlist *d_create_node ( int );  // this is also used in assignment 5 
void display_dlist( dlist * );

//ass 7 cir singly
void a7 ( void );

slist *cir_insert_first ( slist **, int );
slist *cir_insert_last ( slist **, int );

//delete
slist * cir_delete_first ( slist ** );
slist * cir_delete_last ( slist ** );

void cir_display_slist ( slist * );
//ass 8 cir doubly
void a8 ( void );

dlist *d_cir_insert_first ( dlist **, int );
dlist *d_cir_insert_last ( dlist **, int );

void d_cir_display_dlist ( dlist * );

