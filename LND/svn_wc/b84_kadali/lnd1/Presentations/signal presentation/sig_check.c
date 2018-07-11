#include"header.h"

/* declaring own signal handler */

void my_handler (int n);

void ( *p ) ( int );


int main(void)
{
    int num;

    signal (2, SIG_IGN);
    signal (3, my_handler);

    printf ("enter teh num\n");
    scanf ("%d", &num);

    p = signal ( num , SIG_IGN );

    //  p = signal ( num , my_handler );

    /*  check default conditions         */

    if ( p == SIG_DFL  )
    {
        printf ("SIG_DFL\n");
    }
    else if ( p == SIG_IGN  )
    {
        printf ("SIG_IGN\n");
    }
    else 
        printf("in isr\n");
}

/*    my_handler fun() defination     */
void my_handler(int n)    
{
    printf("in my_handler  signum %d\n", n);
    sleep (5);
    /* set up signals  default actions  */
    signal (2, SIG_DFL);
    signal (3, SIG_DFL);

}
