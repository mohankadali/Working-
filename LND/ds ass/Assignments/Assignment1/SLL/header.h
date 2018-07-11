#include<stdio.h>
#include<stdlib.h>

int add_frnt (int);
int add_end (int);
int add_mid (int);
int add_before (int, int);
int add_after (int,int);
int add_before_num (int,int);
int add_after_num (int, int);
int add_pen (int);
int add_pos (int, int);
int del_frnt ();
int del_end ();
int del_mid ();
int del_before (int);
int del_after (int);
int del_before_num (int);
int del_after_num (int);
int del_pen ();
int del_pos (int);

void print();

typedef struct st
{
	int data;
	struct st *link;
}node;

int size;
