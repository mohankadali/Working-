#include<stdlib.h>
#include<stdio.h>
#include<string.h>
question2(){
    int c=0,x=0;
    char *a;
    FILE *fptr;
    fptr = fopen(__FILE__,"r");
    while(fgetc(fptr)!=EOF){
        c++;
    }
    rewind(fptr);
    a=malloc(c+1);
    while(fgets(a,c,fptr)){
        ++x;
        if(strstr(a,"fptr")){
            printf("%d %s\n",x,a);
        }
    }

    fclose(fptr);
}


