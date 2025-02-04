/*  add at begin */ 

void push(struct Node** ptr, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*ptr);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if((*ptr) !=  NULL)
        (*ptr)->prev = new_node ;

    /* 5. move the head to point to the new node */
    (*ptr) = new_node;
}

/* add at middle */


void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}



/* Given a reference (pointer to pointer) to the head
 *    of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so
     *           make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
     *           node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    /* 3. put in the data  */
    new_node->data  = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}











