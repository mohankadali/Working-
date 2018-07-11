#if 0
#include<stdio.h> 
int main(void)
{
    char a[] = "hellohdbvgsdtwrs";
    int i,j;
    for(i=0 ; a[i];i++)
    {
        for(j=0;a[j];j++)
        {
            if(a[i] == a[j])
                break;
        }
        if(i==j)
            printf("%c ",a[i]);

    }



    return 0;
}

#endif

#if 1



# include <stdio.h>
# include <stdlib.h>
# define NO_OF_CHARS 256
# define bool int

char *removeDups(char *str)
{
    bool bin[NO_OF_CHARS] = {0};
    int i = 0, r = 0;
    char temp;    

    while (*(str + i))
    {

        temp = *(str + i);

        if (bin[temp] == 0)
        {
            bin[temp] = 1;
            *(str + r) = *(str + i);
            r++;
        }

        i++;
    }      

    *(str+r) = '\0';   

    return str;
}

int main()
{
    char str[] = "helloo";
    printf("%s", removeDups(str));
    getchar();
    return 0;
}


#endif
