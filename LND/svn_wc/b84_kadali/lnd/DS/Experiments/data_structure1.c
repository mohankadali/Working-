#include<stdio.h> 
#include<stdlib.h>
#define MAX 10
typedef struct st
{
    int r;
    struct  st *next ;
}ST;

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(ST *ptr, int n)
{
    int len = 0, i;
    ST *temp = ptr;

    // 1) count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    // check if value of n is not more than length of the linked list
    if (len < n)
        return;

    temp = ptr;

    // 2) get the (n-len+1)th node from the begining
    for (i = 1; i < len-n+1; i++)
        temp = temp->next;

    printf ("%d ", temp->data);

    return;
}




void add_begin(ST **ptr)
{
    ST *temp;
    temp = (ST*) malloc(sizeof(ST));
    printf("enter the data...\n");
    scanf("%d",&temp->r);
    if(*ptr == 0)
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        temp->next = *ptr;
        *ptr = temp;
    }
}

void add_end(ST **ptr)
{
    ST *temp;
    temp = (ST*) malloc(sizeof(ST));
    printf("enter the data...\n");
    scanf("%d",&temp->r);
    if(*ptr == 0)
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        ST *temp1 = *ptr;
        while(temp1->next)
        {
            temp1= temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void add_middle(ST **ptr)
{
    ST *temp;
    temp = (ST*) malloc(sizeof(ST));
    printf("enter the data...\n");
    scanf("%d",&temp->r);
    if(*ptr == 0 || (*ptr)->r > temp->r)
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        ST *temp1 = *ptr;
        while(temp1)
        {
            if( temp1->next == 0 || temp1->next->r > temp->r )
            {
                temp->next = temp1->next;
                temp1->next = temp;
                break;
            }    
            temp1= temp1->next;
        }
    }
}
void rev(ST **ptr)
{
    ST *pri = 0,*cur = 0,*nex= *ptr; 
    while(nex)
    {
        cur = nex;
        nex = cur->next;
        cur->next = pri;
        pri = cur;
    }
    *ptr = cur; 
}
void display(ST *ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->r);
        ptr = ptr->next;
    }
    printf("\n");
}
void print_middle(ST *ptr)
{
    ST *slow = ptr;
    ST *fast = ptr;
    while(fast && fast->next)
    {
        slow = slow ->next;
        fast = fast ->next->next;
    }
    printf("middle node = %d\n",slow->r);
}

void circular(ST *ptr)
{
    if (ptr == NULL)
        printf("yessss...\n");

    ST *temp = ptr->next;

    while (temp->next != ptr && temp->next != NULL)
        temp = temp->next;

    if(temp == ptr)
        printf("yesss...\n");
    else
        printf("no,this is not a circular...\n");

}


ST* recrev(ST *ptr)
{
    ST *temp;

    if(ptr == 0 || ptr -> next ==0)
        return ptr;
    temp = recrev (ptr->next);
    ptr->next->next = ptr;
    ptr->next = NULL;
    return temp;
}




void insert(ST **ptr)
{
ST *temp ;
temp = malloc(sizeof(ST));
printf("enter the data to insert...\n");
scanf("%d",&temp ->r);
    

    /* inserting after the node...*/
/* 
   temp ->next = (*ptr)->next;
   (*ptr)->next = temp;
*/

    /* inserting penultimate */


/*
ST *temp1;
temp1 = *ptr;

while(temp1->next->next)
{
temp1= temp1->next;
}
temp->next = temp1->next;
temp1->next = temp;
*/

ST *slow =*ptr,*fast = *ptr;

while(fast->next  &&  fast->next->next  )
{
    slow = slow->next;
    fast = fast->next->next;
}

temp ->next = slow->next;
slow->next =temp;

}

void del(ST **ptr)
{
    ST *temp ;

    /* inserting after the node...*/

/*

    temp  = (*ptr)->next;
    (*ptr)->next = temp->next;
    free(temp);
*/
    /* inserting penultimate */


   
       ST *temp1;
       temp1 = *ptr;

       while(temp1->next->next->next)
       {
           temp1= temp1->next;
       }
       temp =  temp1 ->next ;
       temp1->next = temp->next;
       free(temp);

       /* ST *slow =*ptr,*fast = *ptr;

       while(fast->next  &&  fast->next->next  )
       {
       slow = slow->next;
       fast = fast->next->next;
       }

       temp ->next = slow->next;
       slow->next =temp;
       */
}


int main()
{

    ST *ptr = NULL, *ptr1;
    char ch;
    do
    {
        add_middle (&ptr);
        printf ("enter y if u want to add more....\n");
        scanf (" %c",&ch);
    } while (ch == 'y');
       display (ptr);
        // rev (&ptr);
    //     display (ptr);
      //   print_middle (ptr);
         circular (ptr);
       //  ptr1 = recrev (ptr);
         display (ptr);
      //   */
//    printf("insert any where......\n");
 //   del(&ptr);
  //  display (ptr);
    return 0;
}

