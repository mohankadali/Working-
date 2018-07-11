#include <stdio.h>
int main(){
    int c = 0;
    char ch, ch1;
    FILE *fp1, *fp2;

    fp1 = fopen(__FILE__, "r");    
    fp2 = fopen("output", "w");

    while ((ch1 = fgetc(fp1)) != EOF){
        c++ ;
    }

       fseek (fp1, -1, SEEK_END) ;     
 //  c--;
    for (; c ; c --){
        ch = fgetc(fp1);
        fputc(ch, fp2);
        fseek(fp1, -2, SEEK_CUR) ;     
    }

    printf ("\n**File copied successfully in reverse order**\n");
    fclose (fp1);
    fclose (fp2);
    return 0;
}
