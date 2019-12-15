#include <stdio.h>
int main()
{
    int a[100], size, one;
    int i, j, k;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0; i<size; i++)
    {
        one = 1;

        for(j=i+1; j<size; j++)
        {
            if(a[i]==a[j])
            {
                for(k=j; k<size-1; k++)
                {
                    a[k] = a[k+1];
                }

                size--;
                j--;
                one = 0;
            }
        }
        if(one != 1)
        {
            for(j=i; j<size-1; j++)
            {
                a[j] = a[j+1];
            }

            size--;
            i--;
        }
    }
    printf("\nAll unique elements in the array are:%d\n",size);
    for(i=0; i<size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
} 
