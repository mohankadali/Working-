#include <stdio.h> 
int main (void)
{
    char c [100] = "aradhanakiran";

    memcpy (c+8, c, 20);

    printf ("%s\n", c);

    return 0;
}
