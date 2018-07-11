#include<stdio.h>
struct st{
    unsigned char e_ident[16];
    short e_type;
    short e_machine;
    unsigned int e_entry;
};
question5(){
    FILE *fptr;
    char ch;
    struct st e;
    fptr=fopen("info.db","w");
    printf("enter the e_ident: ");
    scanf("%s",e.e_ident);

    printf("enter the e_type: ");
    scanf("%hd",&e.e_type);

    printf("enter the e_machine: ");
    scanf("%hd",&e.e_machine);

    printf("enter the e_entry: ");
    scanf("%u",&e.e_entry);

    fwrite(&e,sizeof(e),1,fptr);
    printf("successfully recoreded data\n");
    fclose(fptr);
}


