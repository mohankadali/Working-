#include<stdlib.h>
#include<stdio.h> 
typedef struct st
{

    int r;
    struct st *next;

}ST;
void add_begin(ST **ptr )
{
    if(*ptr == NULL)
    {
        ST *temp = (ST*) malloc (sizeof (ST) ); 
        printf("enter the data for first node...\n");
        scanf("%d",&temp->r);

        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        ST *temp1 = *ptr;
        while(temp1->next)
        {
            temp1 = temp1->next;
        }
        ST *temp = (ST*) malloc (sizeof (ST) ); 
        printf("enter the data...\n");
        scanf("%d",&temp->r);
        temp->next = temp1->next;
        temp1->next = temp;
    }

}

void print(ST *ptr)
{
    if(ptr == 0)
        printf("list is emty....\n");
    else
    {
        while(ptr)
        {
            printf("%d ",ptr->r);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{

    ST *hptr = NULL ;
    print(hptr);

    char ch;
    do
    {
        add_begin(&hptr);
        printf("enter y if u want more...\n");
        scanf(" %c",&ch);
    }while(ch == 'y');
    print(hptr);
}
