#include<stdio.h> 
main()
{
    int a[10],b[5]={1,4,7,9,11},c[5]={2,3,6,14,30};
    int i=0,j=0,k=0;
    while (i < 5 && j < 5) 
    {
        if(b[i]<c[j])
        {
            a[k]=b[i];
            i++;
            k++;
        }
        if(b[i]>c[j])
        {
            a[k]=c[j];
            j++;
            k++;
        }
    }
    while(i<5)
    {
        a[k]=b[i];
        i++;
            k++;
    }
    while(j<5)
    {
        a[k]=c[j];
        j++;
            k++;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}
