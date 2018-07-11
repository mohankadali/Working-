#include<stdio.h>
#include<stdlib.h>
typedef struct st 
{
    int r;
    struct st *next;
}STACK;
STACK *root = NULL;
STACK *temp1;
void push (int num)
{
    if(root == NULL)
    {
        root = malloc(sizeof(STACK));
        root ->r = num;
        root->next = NULL;
    }
    else
    {
        STACK *temp = malloc(sizeof(STACK));
        temp ->r = num;
        temp ->next = root;
        root = temp;
    }
}
void pop()
{

    temp1 = root;
    while(temp1 -> next -> next)
    {
        temp1 = temp1 -> next;
    }
    free(temp1 -> next);
    temp1 -> next = NULL;
}
void display()
{

    temp1 = root;
    while(temp1)
    {
        printf("%d ",temp1 ->r);
        temp1 = temp1 -> next;
    }
    printf("\n");
}
int main(void)
{

    push (10);
    display ();
    push (20);
    display ();
    push (30);
    display ();
    push (40);
    display ();
    push (50);
    display ();
    pop ();
    display ();
    pop ();
    display ();
    pop ();
    display ();
    pop ();
    display ();
}
