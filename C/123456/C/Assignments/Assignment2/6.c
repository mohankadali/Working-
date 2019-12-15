char strcm (char *str1, char * str2)    //called function
{
    int i;
    for(i=0;str1[i];i++)
    {
        if(str1[i]!=str2[i])            //comparing  the two strings
            break;
    }
    if(str1[i]==str2[i])
        return 0;
    if(str1[i]>str2[i])
        return 1;
    if(str1[i]<str2[i])
        return -1;
return 0;
} 
