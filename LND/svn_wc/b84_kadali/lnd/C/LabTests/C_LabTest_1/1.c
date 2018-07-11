#include<stdio.h> 
#include<string.h>
main()
{
    int i,j=0,k=0;
    char str[100],word[20],dummy[20][20];
    printf("enter the source string......\n");
    scanf("%[^\n]s",str);                                   //giving input string
    for(i=0;str[i];i++)                                     //     
    {
        if(str[i]==' ')
        {
            dummy[k][j]='\0';
            k++;
            j=0;
        }
        else
        {
            dummy[k][j]=str[i];
            j++;
        }
    }
    dummy[k][j]='\0';
    printf("enter the word we want to remove..\n");
    scanf("%s",word);
    for(i=0;i<k+1;i++)
    {
        if(strcmp(dummy[i],word)==0)
        {
            for(j=i;j<k+1;j++)
            {
                strcpy(dummy[j],dummy[j+1]);
            }
            k--;
        }
    }
    for(i=0;i<k+1;i++)
    {
        printf("%s ",dummy[i]);
    }
    printf("\n");
}
