#include<stdio.h> 
#include<string.h>
main()
{
    int i,j=0,k=0,a[20],c=0,p=0,max=0,min=0;
    char str[100],dummy[20][20];
    printf("enter the source string......\n");
    scanf("%[^\n]s",str);                                   
    for(i=0;str[i];i++)                                         
    {
        if(str[i]==' ')
        {
            dummy[k][j]='\0';
            k++;
            j=0;
            a[p++]=c;
            c=0;
        }
        else
        {
            c++;
            dummy[k][j]=str[i];
            j++;

        }
    }


    dummy[k][j]='\0';
    for(i=0;i<k+1;i++)
        printf("%is",a[i]);
    printf("\n");


}
