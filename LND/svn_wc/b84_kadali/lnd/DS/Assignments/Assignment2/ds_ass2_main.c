#include <stdio.h>

#include "ds_ass2_header.h"


int my_atoi ( char * );

int main(void)
{

    int opt;

    char *f_ret;

    while ( 1 ) {

        __fpurge ( stdin );

        printf ("\n \n");
        printf ("\nEnter option : \n1:Searching\n2:Sorting\n3:Tree\n4:Exit\n\n");

     //   scanf ("%d", &opt );

        f_ret = fgets ( ( char * )&opt,3 , stdin );

        opt = my_atoi ( f_ret );



        switch ( opt )
        {
            case 1: 
                searching();

                break;

            case 2:
                sort();
                break;

            case 3:
                Btree ();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf ("\nEnter a valid option \n");
                break;
        }
    }

}

int my_atoi ( char *ptr )
{

    int sum = 0;

    int iter;

    for ( iter = 0; ptr [ iter ] != '\n'; iter ++ ) {

        sum = sum * 10 + ( (ptr [ iter ] - '0') );
    }

    return sum;
}
