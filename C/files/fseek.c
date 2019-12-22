#include<stdio.h> 
#include<string.h>
int main(void)
{

    FILE *fp;
    fp = fopen("data","r+");
    char ch[100];
    int c=0,p;

    while( fscanf(fp,"%s",ch) != EOF )
    {
        printf("%s\n",ch);

        ch[0] = ch[0] ^ (1<<5) ;

        p = strlen(ch);

        fseek(fp,-p,SEEK_CUR);

        fprintf(fp,"%s",ch);

    }
    return 0;
}
