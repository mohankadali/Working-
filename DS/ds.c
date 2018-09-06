#include <stdio.h>
#include <stdlib.h>
typedef struct st{
        int r;
        struct st *next;
}ST;

void add_first(ST **ptr)
{
        ST *temp;
        temp = (ST *)malloc(sizeof(ST));
        temp -> r  = 1 ; 
        temp -> next = *ptr;
        *ptr = temp;                
}

void add_begin(ST **ptr)
{
        if (*ptr == NULL)
        {
                return ;
        }
        else{
                ST *temp;
                temp = (ST *)malloc(sizeof(ST));
                temp -> r  = 2 ; 
                temp -> next = *ptr;
                *ptr = temp;                
        }
}

void add_end(ST **ptr)
{

        ST *temp, *temp1 = *ptr;
        temp = (ST *)malloc(sizeof(ST));
        temp -> r  = 3 ; 
        while(temp1 -> next)
        {
                temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        temp1 -> next = temp;

}

void add_rear(ST **ptr)
{
        ST *temp,*temp1 = *ptr;
        temp = (ST *)malloc(sizeof(ST));
        temp -> r  = 4 ; 
        while(temp1->next ->next)
        {
                temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        temp1 -> next = temp;

}

void add_middle(ST **ptr)
{
        ST *temp;
        ST *fast = *ptr,*slow= *ptr;
        temp = (ST *)malloc(sizeof(ST));
        temp -> r  = 5 ; 
        while(fast ->next && fast -> next -> next) //check for odd and even nodes respectively 
        {
                slow= slow->next;
                fast = fast -> next -> next;
        }
        temp -> next = slow->next;
        slow -> next = temp;
}

void swap(ST *a, ST *b)
{
        int temp = a->r;
        a->r = b->r;
        b->r = temp;
}

void bubblesort(ST *start)
{
        int swapped, i;
        ST *ptr1;
        ST *lptr = NULL;
        /* Checking for empty list */
        if (start == NULL)
                return;
        do
        {
                swapped = 0;
                ptr1 = start;

                while (ptr1->next != lptr)
                {
                        if (ptr1->r > ptr1->next->r)
                        { 
                                swap(ptr1, ptr1->next);
                                swapped = 1;
                        }
                        ptr1 = ptr1->next;
                }
                lptr = ptr1;
        }
        while (swapped);
}

void display(ST *ptr)
{
        if (ptr)        
        {
                while(ptr)
                {
                        printf("%d ",ptr -> r);
                        ptr = ptr -> next;
                }
                printf("\n");
        }        
        else
        {
                printf("list is empty ....\n");
        }
}

void print_nth_from_last(ST *head, int n)
{
        int len = 0, i;
        ST *temp = head;
        // 1) count the number of nodes in Linked List
        while (temp != NULL)
        {
                temp = temp->next;
                len++;
        }
        // check if value of n is not more than length of the linked list
        if (len < n)
                return;
        temp = head;
        // 2) get the (len-n+1)th node from the begining
        for (i = 0; i < len-n; i++)
        {
                temp = temp->next;
        } 
        printf ("nth node from last is :%d\n", temp->r);
        return;
}
void search_number(ST *ptr, int num)
{
        ST *temp,*temp1;
        temp = ptr;
        int pos = 0;
        while(temp->next)
        {
                if(temp->r == num)
                        printf("position: %d\n",pos);
                temp = temp-> next;                
                pos++;
        }
}

int largest_element(ST* head)
{
    int max = -32767;
 
    while (head != NULL) {
 
        if (max < head->r)
            max = head->r;
        head = head->next;
    }
printf("max:%d\n",max);
}
 
int smallest_element(ST* head)
{
    int min = 32767;
 
    while (head != NULL) {
 
            if (min > head->r)
                    min = head->r;

            head = head->next;
    }
    printf("min:%d\n",min);
}
void reverse (ST **ptr)
{
        ST *pri =NULL,*cur = NULL, *nex = *ptr;
        int *p = 0;
        printf("%d\n",*p);       
        while(nex)
        {
                cur = nex;
                nex = cur -> next;
                cur -> next = pri;
                pri = cur;
        }
        *ptr = cur;
}

void remove_duplicates(ST *start)
{
    ST *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    while (ptr1 && ptr1->next )
    {
        ptr2 = ptr1;
 
        while (ptr2->next)
        {
            if (ptr1->r == ptr2->next->r)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else 
                    ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void delete_beg(ST **ptr)
{
        ST *temp;
        temp = *ptr;
        *ptr = temp -> next;
        free(temp);
}

void delete_rear(ST **ptr)
{
        ST *temp = *ptr;
        ST *temp1 = *ptr;
        while (temp1 -> next -> next )
        {
                temp = temp1;
                temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        free(temp1);
}
void delete_nth(ST **ptr,int n)
{
        ST *temp1 = *ptr;
        ST *temp = *ptr;

        int c = 0;
        while(c <= n)
        {
                temp = temp1;
                temp1 = temp1->next;
                c++;
        }
        temp -> next = temp1 -> next;
        free(temp1);
}
void delete_list(ST **ptr)
{
        ST *temp = *ptr;
        ST *temp1 = *ptr;
        while(temp -> next)
        {
                temp1 =  temp -> next;
                free(temp);
                temp = temp1;
        }
*ptr = NULL;
}
int main()
{

        ST *hptr =NULL ; 
        /**** inserting the node *****/ 
        add_first(&hptr);
        display(hptr);
        add_begin(&hptr);
        display(hptr);
        add_end(&hptr);
        display(hptr);
        add_rear(&hptr);        
        display(hptr);
        add_middle(&hptr);        
        display(hptr);
        bubblesort(hptr);
        display(hptr);
        print_nth_from_last(hptr,4);
        search_number(hptr, 2);
        largest_element(hptr);
        smallest_element(hptr);
        reverse(&hptr);      
        display(hptr);
                
/***** deleting the nodes  *****/
/*
       remove_duplicates(hptr);
       display(hptr);
       delete_beg(&hptr);
       display(hptr);
       delete_rear(&hptr);
       display(hptr);
       delete_nth(&hptr,1);
       display(hptr);
*/
//        delete_list(&hptr);  
  //      display(hptr);

     return 0;
}


