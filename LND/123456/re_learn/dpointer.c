#include <stdio.h>  
int main(void)  
{   
    char *ptr = "mishra";
    printf ("%p\n",ptr);
    printf ("%p\n",&ptr);
    printf ("%c\n",*ptr );
    printf ("%c\n",ptr[0]);
    return 0;
}
