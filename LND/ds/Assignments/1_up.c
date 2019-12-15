#include<stdio.h> 
#define MAX 4 
int STACK[MAX];
int top=0;
void print()
{
    int i;
    for(i = 1 ; i <= top ; i++)
    {
        printf("%d  ",STACK[i]);
    }
    printf("\n");
}
void push(int data)
{
    if( top == MAX )
    {
        printf("stack already full......\n");
        exit(0);
    }
    else
    {
        STACK[++top]=data;
        printf("address of stack in push operation=%p\n",&STACK[top]);
    }
}
void pop()
{
    if(top == -1)
    {
        printf("stack is already empty.....\n");
        exit(0);
    }
    else
    {
        --top;
        printf("address of stack in pop operation=%p\n",&STACK[top]);
    }
}
int main()
{
    int data,option;
    char ch;
    do
    {
        printf("enter the option 1  ->  push,  2  ->  pop...\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("enter the data...\n");
                scanf(" %d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            default:
               // print();
                break;
        }
                print();
        printf("enter y if u want to add more.....\n");
        scanf(" %c",&ch);
    }while(ch=='y');
}






