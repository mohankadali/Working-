#include<stdio.h>
#include"header.h"

/* declaration of my_handler */
void my_handler (int n);

int main(void)
{

    struct sigaction v; 
    printf(" hello pid = %d\n", getpid ());

    v.sa_handler = my_handler;

    /*allows  all other except 3 */

    sigemptyset (&v.sa_mask ); 
    sigaddset (&v.sa_mask, 3);   


    /*     block other signal except SIGQUIT (3)*/ 

    /*    sigfillset ( &v.sa_mask);
          sigdelset ( &v.sa_mask, SIGQUIT);
          */

    sigaction  ( 2 , &v , 0);
    printf("hai\n");

    while (1);
}



/* defination of my_handler () */
void my_handler (int n)
{
    printf ("in my handler  %d\n", n);
    sleep (10);
}
