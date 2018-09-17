#include <stdio.h>
#include <stdlib.h>

typedef struct st{
        int r;
        struct st *next;
}ST;

create_node(ST **ptr)
{
        ST *temp = (ST*) malloc(sizeof(ST));
        temp -> r = 1;
        temp -> next = NULL;
        *ptr = temp;
}
ST *add_begin(ST **ptr)
{
        if(*ptr == NULL)
        {
                printf("node not yet created..\n");
                return;
        }

        ST *temp = (ST*) malloc(sizeof(ST));
        temp -> r = 2;
        temp ->next = *ptr;
        *ptr = temp;
}
ST* add_end(ST **ptr)
{

        if(*ptr == NULL)
        {
                printf("node not yet created..\n");
                return;
        }
        ST *temp1 = *ptr;
        ST *temp = (ST*) malloc(sizeof(ST));
        temp -> r = 3;
        while(temp1 -> next)
        {
                temp1 = temp1 -> next;
        }

        temp -> next = temp1 -> next;
        temp1 -> next = temp;
}
void display(ST *ptr)
{
        while(ptr)
        {
                printf("%d ",ptr -> r);
                ptr = ptr-> next;
        }
        printf("\n");
}
ST* add_sorted_order(ST **ptr)
{

        if(*ptr == NULL)
        {
                printf("node not yet created..\n");
                return;
        }
        ST *temp1 = *ptr;
        ST *temp = (ST*) malloc(sizeof(ST));
        temp -> r = 4;

        if(*ptr == NULL || (*ptr) -> r > temp -> r)
        {
                temp -> next = *ptr;
                *ptr = temp;
        }
        while(temp1)
        {
                if(temp1 -> next == NULL || temp1 -> next -> r > temp ->r)
                {
                        temp -> next = temp1 -> next;
                        temp1 -> next = temp;
                        break;
                }
                temp1 = temp1 -> next;
        }
}
ST *add_middle(ST **ptr)
{

        ST *fast, *slow;
        fast = slow = *ptr;

        while(fast-> next && fast -> next -> next)
        {
                fast = fast -> next -> next;
                slow = slow -> next;
        }

        if(*ptr == NULL)
        {
                printf("node not yet created..\n");
                return;
        }
        ST *temp = (ST*) malloc(sizeof(ST));
        temp -> r = 5;

        temp -> next = slow -> next;
        slow -> next = temp;

}
void print_nth_from_last(ST *ptr, int n)
{
        int l=0;
        ST *temp = ptr;
        while(temp)
        {
                temp = temp -> next;
                l++;
        }
        temp = ptr;
        int i;
        for(i=0;i<l-n;i++)
        {
                temp = temp->next;
        }

        printf("%d \n",temp ->r);

}
ST *rev(ST **ptr)
{
        ST *pri =  NULL;
        ST *cur = NULL;
        ST *nex = *ptr;
        while(nex)
        {
                cur = nex;
                nex = cur -> next;
                cur -> next = pri;
                pri = cur;
        }
        *ptr = cur;
}
ST* recrev(ST *ptr)
{
        if (ptr == NULL || ptr -> next)
                return ptr;
        ST *temp = recrev(ptr ->next);
        ptr -> next -> next = ptr;
        ptr -> next = NULL;
        return temp;
}
int main()
{
        ST *hptr = NULL;
        create_node(&hptr);
        display(hptr);       
        add_begin(&hptr);
        display(hptr);       
        add_end(&hptr);
        display(hptr);       
        add_sorted_order(&hptr);
        display(hptr);       
        add_middle(&hptr);
        display(hptr);       
        print_nth_from_last(hptr,4);
        rev(&hptr);        
        display(hptr);       
        recrev(hptr);        
        display(hptr);       
return 0;
}
