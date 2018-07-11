#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    unsigned char *p = (unsigned char*)malloc(4*sizeof(unsigned char));
    memset(p,0,4);
    printf ("%d\n",*p);
    strcpy((char*)p,"abcdabcd"); 
    printf ("%p\n",p);
    free(p); 
    printf ("%p\n",p);
    return 0;
}
