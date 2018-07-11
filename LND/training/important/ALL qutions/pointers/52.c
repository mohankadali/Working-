#include <stdio.h>
int main()
{
        char  p[] = "abc";
        printf ("%c \n", *p++);
        printf ("%c \n", ++*p);
        printf ("%c \n", (*p)++);
        return 0;
}
