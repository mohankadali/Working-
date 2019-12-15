#include"header.h"
void push(STACK *stack, char data)
{
    stack -> array[++(stack -> top)] = data;
}
