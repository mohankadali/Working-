#include <stdio.h>
#include "Declartaion.h"

char* my_strtok(char *buf, const char *deli)
{
        static int last=1;
        static char *prev;
        int fwd, loop;
        if (NULL == buf){
                buf = prev;
        }
        for (fwd=0; buf[fwd]; fwd++){
                for(loop=0; deli[loop] != '\n'; loop++){
                        if(buf[fwd] == deli[loop]){
                                buf[fwd]='\0';
                                prev=buf+fwd+1;
                                return buf;
                        }
                }
        }
       if( (1 ==last) && (prev != NULL)){
              last=0;
             return buf;
       } 
        return NULL;
}






