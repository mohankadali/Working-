#include"header.h"


int main (void){                                        //main starts from here    

    char str[MAX];
    int i;

    printf ("enter the string....\n");
    fgets (str, MAX, stdin);

    for (i = 0; str[i] != '\n'; i++);                          //removing new line in fgets
    str[i] = '\0';

    printf ("%d\n", strlen (str));                       //finding length of str
    char temp[20];
   
    strcpy (temp, str);                                 //copying 

    reverse (str);                                      //calling functiom        

    if (strcmp (temp,str)){                              //comparing both  strings
        printf ("it is not a palindrome.....\n");
    }
    else{
        printf ("yes it is a palindrome.....\n");
    }
    return 0;
}
