#include <stdio.h>
#include <stdlib.h>
typedef struct st{
        int r;
        struct st *next;
}STACK;
STACK *top = NULL;
void push (int data)
{
        if(top == NULL)
        {
                top = (STACK*)malloc(sizeof(STACK));
                top -> r = data;
                top -> next = NULL;
        }
        else
        {
                STACK *temp = (STACK*)malloc(sizeof(STACK));
                temp -> r = data;
                temp -> next = top;
                top = temp;
        }
}
void pop()
{
        STACK *top1 = top;
        top1 = top -> next;
        free(top);
        top = top1; 
}
void display()
{
        STACK *top1 = top;
        while(top1)
        {
                printf("%d ",top1->r);
                top1 = top1 -> next;
        }
        printf("\n");
}
int main()
{

        push (10);
        display();
        push (20);
        display();
        push (30);
        display();
        push (40);
        display();
        push (50);
        display();
        push (60);
        display();
        push (70);
        display();
        pop();
        display();
        pop();
        display();
        pop();
        display();
        pop();
        display();
        pop();
        display();
        return 0;
}
