#include"header.h"
STACK *create (int max)
{
    STACK *stack = malloc (sizeof (STACK));
    stack -> size = max;
    stack -> top = -1;
    stack -> array = malloc ((stack -> size) * sizeof (char));
    return stack;
}

