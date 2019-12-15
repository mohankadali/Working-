#include<stdio.h>
struct st{
    unsigned char e_ident[16];
    short e_type;
    short e_machine;
    unsigned int e_entry;
};
question6(){
    FILE *fptr;
    char ch;
    struct st e;
    fptr=fopen("info.db","r");

    fread(&e,sizeof(e),1,fptr);
    printf("%s\n %hd\n %hd\n %u\n",e.e_ident,e.e_type,e.e_machine,e.e_entry);
    fclose(fptr);
}


