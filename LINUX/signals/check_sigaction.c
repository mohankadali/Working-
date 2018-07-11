#include<stdio.h>
#include<signal.h>
#include<unistd.h>

/*declartion of my_handler*/
void my_handler (int n);


int main(void)
{
    struct sigaction v;

    v.sa_handler = my_handler;  
    int num;

    //    signal (2, my_handler);

    printf ("enter the num\n");
    scanf ("%d", &num);

    /*   not setting new action, collecting  old action   */
    sigaction (num, NULL, &v);

    /* check current signal action  */

    if ( v.sa_handler == SIG_IGN)
        printf ("previous action = IGN\n");
    else if (v.sa_handler == SIG_DFL)
        printf (" previous action = DFL\n");
    else 
        printf (" previous action = in isr\n");

}

/* defination of my_handler () */
void my_handler (int n)
{
    printf("in my_handler\n");
}
