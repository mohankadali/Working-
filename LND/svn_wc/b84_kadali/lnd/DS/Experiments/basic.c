#include <stdio.h>
#include <stdlib.h>

typedef struct st{

    int r;
    struct st *next;
}ST;

void add_begin(ST** ptr)
{
    ST *temp;
    temp = malloc(sizeof(ST));
    printf("enter the data...\n");
    scanf("%d",&temp -> r);

    if(*ptr == 0)
    {
        temp -> next = *ptr;
        *ptr = temp;  
    }
    else
    {
        temp -> next = *ptr;
        *ptr = temp;  
    }
}
void add_end(ST **ptr)
{

    ST *temp,*temp1;

    temp = malloc(sizeof(ST));
    printf("enter the data...\n");
    scanf("%d",&temp -> r);
    if(*ptr == 0)
    {
        temp -> next = *ptr;
        *ptr = temp;  
    }
    else
    {    
        temp1 = *ptr;

        while(temp1 -> next)
        {
            temp1 = temp1 -> next;
        }

        temp->next = temp1 ->next;
        temp1 -> next = temp;
    }
}
void print(ST *ptr)
{

    while(ptr)
    {
        printf("%d ",ptr -> r);
        ptr = ptr -> next;
    }
    printf("\n");
}
void insert(ST **ptr)
{
    ST *temp,*temp1;
    temp1 = *ptr;  
    int c = 0;
    while( c < 3 )
    {
        temp1 = temp1 -> next;
        c++;
    }
    temp = malloc(sizeof(ST));
    printf("enter the data to insert in 3rd position ...\n");
    scanf("%d",&temp -> r);
    temp -> next = temp1 -> next;
    temp1 -> next = temp; 
} 
void reverse(ST **ptr)
{

    ST *pri = 0,*cur = 0, *nex = *ptr;

    while(nex)
    {
        cur = nex;
        nex = cur->next;
        cur->next = pri;
        pri = cur;
    }
    *ptr = cur;
}
void delete(ST **ptr)
{

    ST *temp,*temp1;

    if(*ptr == 0)
        return ;
    else
    {
        temp = *ptr;

        temp = temp -> next;
        free (*ptr);

        *ptr = temp;
    }

}
int main()
{

    ST *hptr = 0;
    char ch;
    do
    {
        add_end(&hptr);
        printf("enter y if u want to add more...\n");
        scanf(" %c",&ch);
    }while(ch == 'y');
    print(hptr);
    insert(&hptr);
    print(hptr);
    reverse(&hptr);
    print(hptr);
    delete(&hptr);
    print(hptr);
    return 0;
}
