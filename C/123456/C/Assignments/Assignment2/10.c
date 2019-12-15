int palindrome(char *str)   //called function
{
    int  i , j ; 
    for(i=0;str[i]!='\n';i++);
    str[i]='\0';
    for(i=0;str[i];i++);
    for(j=0,i=i-1;str[j];i--,j++)
    {
        if(str[j] != str[i])  // checking for palindrome condition
        {
            break;
        }
    }
    if(str[i]==str[j])
        return 1;
    else
        return 0;
}
