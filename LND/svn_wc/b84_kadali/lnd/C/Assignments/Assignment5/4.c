#include<stdlib.h>
#include<stdio.h>
#include<string.h>
question4(){
    int c=0,x=0;
    char *a;
    FILE *fptr;
    fptr = fopen("1","r");
    while(fgetc(fptr)!=EOF){
        c++;
    }
    rewind(fptr);
    a=malloc(c+1);
    while(fscanf(fptr,"%s",a)!=EOF){
        x++;
    }
    printf("no of words=%d\n",x);
    fclose(fptr);
}

