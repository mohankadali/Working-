#include <stdio.h>
int main() 
{ 
        unsigned char *c; 
        c = 'A'; 

        while (c >= 0) 
                printf("%d\n", (*c)++); 
} 

