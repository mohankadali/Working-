#include<stdio.h>
void swap(char *str1, char *str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}  

int main()
{
    char *str1 = "Geeks";
    char *str2 = "Quiz";
    swap(str1, str2);
    printf("str1 is %s, str2 is %s", str1, str2);
    return 0;
}
