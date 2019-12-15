#include"header.h"
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

