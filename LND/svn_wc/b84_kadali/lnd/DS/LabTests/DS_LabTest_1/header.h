#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#define MAX 20
typedef struct st
{
    int top;
    int size;
    char *array;
} STACK;



STACK *create(int);

char pop(STACK*);

void push(STACK*,char);

void reverse (char *);


