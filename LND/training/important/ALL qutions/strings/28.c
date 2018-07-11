#include <stdio.h>
int main() 
{ 
        char str[]="Sony is Japanese based company" ;
        char *tmp,*s; 
        tmp=str; 
        s=strstr(str,"Japanese "); 
        printf("%d %d\n",&tmp, &s); 
        strcat(tmp,s); 
        printf("%s",s); 
} 
