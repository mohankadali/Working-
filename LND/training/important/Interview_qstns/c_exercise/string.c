#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100


void reverseWords( char * str )
{
    int i = 0, j = 0;
    reverseString( str, strlen(str) ); // tsaf yrev si rac yM
    while( 1 ) // Loop forever
    {
        if( *(str+j) == ' ' || *(str+j) == '\0') // Found a word or reached the end of sentence
        {
            reverseString( str+i, j-i );
            i = j+1;
        }
        if( *(str+j) == '\0')
        {
            break;
        }
        j++;
    }
}

void reverseString(char* str, int len)
{
    int i, j;
    char temp;
    i=j=temp=0;

    j=len-1;
    for (i=0; i<j; i++, j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

int main()
{
        char *str;
     //   char *str2;
//	int num;

        str = malloc(size);

        printf("\n ENTER A STRING…:\n ");
        fgets(str,size,stdin);

//	printf("\n enter the length of the string we need to copy : \n");
//	scanf("%d",&num);

        reverseWords(str);

	printf("%s",str);

        free(str);
        //free(str2);

        return 0;
}
