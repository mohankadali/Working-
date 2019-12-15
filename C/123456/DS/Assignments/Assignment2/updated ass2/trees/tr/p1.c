#include<stdio.h>
#include"header.h"
#include<stdlib.h>

int main(void)
{

    int opt;
    int data;
    char ch;
    char *sbuf,*cbuff  ;

    struct node * root= NULL ;



    while ( 1 ) {

        printf("Enter the option\n1:insert\n2:minimum \n3:exit\n\n");

        sbuf = fgets ( (char *)&opt, sizeof(int),stdin);

        opt = atoi ( sbuf );

        switch ( opt )
        {

            case 1:  printf("enter the data you want to enter");
                     sbuf=fgets( ( char *)&data ,sizeof(int),stdin);
                     data = atoi (sbuf);
                     printf ("%d\n", data);
                     root = insert(root,data);

                     break;


            case 2 :  root =   traversal_left_side ( root );
                     printf(" minimum value: %d\n",root->info);

                     break;

            case 3: exit (0);

            default :
                    printf("\n Enter a valid option\n");
                    break;


        }
    }

}




