#define SIZE 100
#define MAX 10 
#include<stdio.h> 
int main()
{
   // int STACK[MAX];
    static int top=MAX;
    int STACK[MAX];

    int data,option;
    char c;

    do
    {
        printf("enter the option 1  ->  push,  2  ->  pop...\n");
        fgets((char*)&option,SIZE,stdin);
        option = atoi((char*)&option);
        switch(option)
        {
            case 1:
                printf("enter the data...\n");
                fgets((char*)&data,SIZE,stdin);
                data = atoi((char*)&data);

                printf("address of data =%p   \n",&data); 
                push(&top,data,STACK);
                break;
            case 2:
                pop(&top,STACK);
                break;
            default:
                break;
        }
        print(&top,STACK);
        printf("enter y if u want to add more.....\n");

        fgets(&c,10,stdin);
    }while(c=='y');
    return 0;
}


//void pop(int *top,int *STACK)
void pop(int *top,int STACK[])
{
printf("sizeof stack=%d\n",sizeof(STACK));
    if(*top >= MAX )
    {
        printf("stack is already empty.....\n");
    }
    else
    {
        ++(*top);
        printf("address of stack in pop operation=%p\n",&STACK[*top]);
    }
}



void print(int *top,int *STACK)
//void print(int *top,int STACK[])
{
    int i;
    for(i = MAX ; i > *top ; i--)
    {
        printf("%d  ",STACK[i]);
    }
    printf("\n");
}




//void push(int *top,int data,int *STACK)
void push(int *top,int data,int STACK[])
{
printf("sizeof stack=%d\n",sizeof(STACK));
    if( *top <= 0 )
    {
        printf("stack already full......\n");
    }
    else
    {
        STACK[(*top)--]=data;
        printf("address of stack in push operation=%p\n",&STACK[*top]);
    }
}


