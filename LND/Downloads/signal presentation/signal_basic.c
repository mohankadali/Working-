#include"header.h"

/* declaration of my_handler */
void my_handler (int n);

int main(void)
{
    
    int *p=NULL;

    printf("pid = %d\n",getpid ());
    printf("  wait .. signal will come \n");


    //signal (11, sig_handler);
    signal (11 , my_handler); ///2)sig_handler for signal num 11
 
    signal (2, my_handler); ///1)sig_handler for signal num 2
    printf ("%d\n", *p);

    //   signal (2, SIG_IGN); ///1)ignoring signal num 2


    //    pause ();

    printf(" finally signal arrived hai\n");

    while (1);
}
/*  my_handler () defination */
void my_handler (int n)
{
    sleep (5);
    printf("in sig_handler  signum%d\n", n);
}
