#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
 
void insertEnd(struct Node** start, int value)
{
    if (*start == NULL)
    {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
 
    Node *last = (*start)->prev;
    
    struct Node* new_node = new Node;
    new_node->data = value;
 
    new_node->next = *start;
 
    (*start)->prev = new_node;
 
    new_node->prev = last;
 
    last->next = new_node;
}
 
void insertBegin(struct Node** start, int value)
{
    struct Node *last = (*start)->prev;
 
    struct Node* new_node = new Node;
    new_node->data = value;   // Inserting the data
 
    new_node->next = *start;
    new_node->prev = last;
    last->next = (*start)->prev = new_node;
 
    *start = new_node;
}
 
void insertAfter(struct Node** start, int value1,
                                      int value2)
{
    struct Node* new_node = new Node;
    new_node->data = value1; // Inserting the data
    struct Node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node *next = temp->next;
    new_node->next = next;
    next->prev = new_node;
}
 
 
void display(struct Node* start)
{
    struct Node *temp = start;
 
    printf("\nTraversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
 
    printf("\nTraversal in reverse direction \n");
    Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* start = NULL;
 
    // Insert 5. So linked list becomes 5->NULL
    insertEnd(&start, 5);
 
    // Insert 4 at the beginning. So linked 
    // list becomes 4->5
    insertBegin(&start, 4);
 
    // Insert 7 at the end. So linked list
    // becomes 4->5->7
    insertEnd(&start, 7);
 
    // Insert 8 at the end. So linked list 
    // becomes 4->5->7->8
    insertEnd(&start, 8);
 
    // Insert 6, after 5. So linked list 
    // becomes 4->5->6->7->8
    insertAfter(&start, 6, 5);
 
    printf("Created circular doubly linked list is: ");
    display(start);
 
    return 0;
}
