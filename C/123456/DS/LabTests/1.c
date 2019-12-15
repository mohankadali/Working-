#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define MAX 20
typedef struct st
{
    int top;
    int size;
    char *array;
} STACK;

STACK *create (int size)
{
    STACK *stack = malloc (sizeof (STACK));
    stack -> size = size;
    stack -> top = -1;
    stack -> array = malloc ((stack -> size) * sizeof (char));
    return stack;
}

char pop (STACK *stack)
{
    return stack -> array [(stack -> top)--];
}

void push(STACK *stack, char data)
{
    stack -> array[++(stack -> top)] = data;
}

void reverse (char *str)
{
    int i;
    int n = strlen (str); 

    STACK *stack = create (n);

    for (i = 0; i < n; i++)
        push (stack, str[i]);
    for (i = 0; i < n; i++)
        str[i] = pop (stack);
}

int main (void){                                        //main starts from here    
    char str[MAX];
    int i;
    fgets(str,MAX,stdin);
    for(i=0;str[i]!='\n';i++);                          //removing new line in fgets
    str[i]='\0';
    printf ("%d\n",strlen (str));                       //finding length of str
    char temp[20];
    strcpy (temp, str);                                 //copying 

    reverse (str);

    if (strcmp(temp,str)){
        printf ("it is not a palindrome.....\n");
    }
    else{
        printf ("yes it is a palindrome.....\n");
    }
    return 0;
}
