#include<stdio.h> 
#define n 10
int main (void)
{
    int i,j,temp,a[n];
    printf("enter the elements....\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
            for(i=1;i<n;i++)
            {
                temp=a[i];
                j=i-1;
                while(temp<a[j] && j>=0)
                {
                    a[j+1] = a[j];
                    j--;
                }
                a[j+1] = temp;
            }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
            printf("\n");
}
