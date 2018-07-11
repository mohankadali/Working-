#include"stdio.h" 
struct st
{
    char e;
    int s;
}A[10];     

int main()  
{   
close(1);
    printf("%d\n",sizeof(A));
//open(1); 
    printf("%d    ",sizeof(A));
    /*
    int i;

    for(i= 0; i<5;i++)
    {
        scanf("%d",&A[i].s);
    }
    for(i= 0; i<5;i++)
    {
        printf("%d\n",A[i].s);
    }
    printf("enter characters\n");

    for(i= 0; i<5;i++)
    {
        scanf("%c",&A[i].e);
    }
    for(i= 0; i<5;i++)
    {
        printf("%c\n",A[i].e);
    }*/
    return 0;
}
