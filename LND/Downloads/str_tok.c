#include<stdio.h> 
/* Implementing strtok function */

char * str_tok ( char * buf, const char * delim )
{
    static int last = 1 ;
    static char *prev ;
    int loop_var1 ;
    int loop_var2 ; 
 
    //in recursive call update the buf
    if ( buf == NULL ) {
        buf = prev ;
    }

    for ( loop_var1 = 0 ; buf[loop_var1] ; loop_var1++ ) {
        for ( loop_var2 = 0 ; delim[loop_var2] ; loop_var2++ ) {
            if ( buf[loop_var1] == delim[loop_var2] ) {
               
                //if delimiter found make it to '\0'
               
                buf[loop_var1] = '\0' ;
               
                //store the next token addr in prev
               
                prev = buf + loop_var1 + 1 ;
                return buf ;
            }
        }
    }
    if ( ( last == 1 ) && ( prev != NULL ) ) {
        last = 0 ;
        return buf ;
    }
    return NULL ;
}

int main()
{
char* ret;

printf("enter the string...\n");
scanf("");
ret = str_tok()
}
