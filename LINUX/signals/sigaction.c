#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void my_handler (int n)
{
    printf("in my_handler\n");
}
int main(void)
{
    struct sigaction v, v1;
     printf("pid = %d\n", getpid ());
     v.sa_handler = my_handler;  

     signal (SIGINT , SIG_IGN); 
     sigaction ( SIGINT , &v , &v1 );
     int num;


    //  printf ("enter the num\n");
    // scanf ("%d", &num);

    /*   not setting new action, collecting  old action   */
    //sigaction (num, NULL, &v);

    if ( v1.sa_handler == SIG_IGN)
        printf (" old  action = IGN\n");
    else if (v1.sa_handler == SIG_DFL)
        printf (" old action = DFL\n");
    else 
        printf (" old action = in isr\n");


    while (1);
}
