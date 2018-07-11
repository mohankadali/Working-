#include <stdio.h>
#define size 10
void quick(int [],int ,int);
int main (void)
{
    int i;
    int a[size];
    int low = 0;
    int up = size - 1;
    printf ("enter the elements...\n");
    for (i = 0; i < size; i++)
        scanf ("%d", &a[i]);

    quick (a, low, up);

    for (i = 0; i < size; i++)
        printf ("%d ", a[i]);

    return 0;
}

void quick (int a[], int low, int up)
{
    int i = low + 1;
    int j = up;
    int pivot = a[low];
    int temp;
    while (i <= j)
    {       
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        else
            i++;
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    quick (a, low, j-1);
    quick (a, j+1, up);
}
