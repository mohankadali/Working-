#include<stdlib.h>
#include<stdio.h> 
typedef struct st
{

    int r;
    struct st *next;

}ST;
void add(ST **ptr )
{
    if(*ptr == NULL)
    {
        ST *temp = (ST*) malloc (sizeof (ST) ); 
        printf("enter the data for first node...\n");
        scanf("%d",&temp->r);

        temp->next = temp;
        *ptr = temp;
    }
    else
    {
        ST *temp = (ST*) malloc (sizeof (ST) ); 
        printf("enter the data...\n");
        scanf("%d",&temp->r);

        temp->next = (*ptr)->next;
        (*ptr)->next  = temp;
        *ptr = temp;
    }

}

void print(ST *ptr)
{
    ST *temp = ptr; 
    if(ptr == 0)
        printf("list is emty....\n");
    else
    {
        do
        {
            temp = temp ->next;
            printf("%d ",temp->r);

        }while(temp != ptr ) ;   
    }
    printf("\n");
}

int main()
{

    ST *hptr = NULL ;

    char ch;
    do
    {
        add(&hptr);
        printf("enter y if u want more...\n");
        scanf(" %c",&ch);
    }while(ch == 'y');
    print(hptr);
}
