#include <stdio.h>
#include "Declartaion.h"
void assign9(void)
{
        char str1[99], sstr[99], *ssub;
        fputs("Enter the string \n",stdout);
        if ( NULL == fgets(str1, sizeof(str1), stdin))
                printf("Error in fgets");
        fputs("Enter the string delimeter\n",stdout);
        if ( NULL == fgets(sstr, sizeof(sstr), stdin))
                printf("Error in fgets");
        fputs("you Enterd strings and delimeter before operation\n",stdout);
        fputs(str1, stdout);
        fputs(sstr, stdout);
        printf("After operation:\n");
        ssub=my_strtok(str1,sstr);
        while(NULL!=ssub){
        printf("%s\n", ssub);
        ssub=my_strtok(NULL,sstr);
        }


 
}
