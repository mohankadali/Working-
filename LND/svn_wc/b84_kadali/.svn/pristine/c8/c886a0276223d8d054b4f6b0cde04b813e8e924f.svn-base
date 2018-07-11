#include<stdio.h> 
#include<stdlib.h>
#define MAX 5
void bubble( int a[] )
{
    int c=0;
    int i,j,temp;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX-i; j++)
        {   
            if (a[j] > a[j+1])
            {
                c++;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("c=%d\n",c);
}

int main (void)
{
    int *a, i;

    a =(int*) malloc (sizeof (a) * MAX);

    for (i = 0 ; i < MAX ; i++)
        scanf ("%d", &a[i]);

    bubble (a) ;

    for(i = 0; i < MAX; i++)
        printf (" %d" , a[i] ) ;
    printf ("\n");
    return 0;
}

