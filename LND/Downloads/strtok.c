#include <stdio.h>

//#include "header.h"

char *strt_ok(char *,  char *);

int main ()
{
    char buf[30]; 
    char delim[30];// delimiter
    char *ptr;// char pointer to store strt_ok val
    printf ("enter the string \n");
    scanf(" %s",buf);
    printf ("enter the delimeter string\n");
    scanf(" %s",delim);
    ptr = strt_ok(buf, delim);// called first time 
    printf("ptr points to: %s\n",ptr);
    ptr = strt_ok(NULL, delim);

    printf("2nd time :%s\n",ptr);
    ptr = strt_ok(NULL, delim);

    printf("3rd time :%s\n",ptr);
    ptr = strt_ok(NULL, delim);  

    printf("4th time :%s\n",ptr); 

}

char *strt_ok(char *ptr, char *delim)
{
    static char *test;
    char * hold = test;
    int var;
// hold will hold the pointer until delim is found.
    if (ptr != NULL){// delim found null than change hold to after null ptr
        test = ptr;
        hold = test;
    }
    while(*test) {// check for delim
        for (var = 0; delim[var]; var ++) {
            if (*(test) == delim[var]){
                *(test)='\0';
                test++;
               return hold;
            }
        }
        test++;
    }
    return hold;
}
