char strcasecm(char *str1, char * str2)
{
    int i;
    for(i=0;str1[i];i++)            //converting to lower case
    {   
        if(str1[i]>='A' && str1[i]<='Z')        
        {
            str1[i]=str1[i]+32;
        }
        if(str2[i]>='A' && str2[i]<='Z')        
        {
            str2[i]=str2[i]+32;
        }
    }
    for(i=0;str1[i];i++)
    {
        if(str1[i]!=str2[i])        //comparing two strings
        {
            break;
        }
    }
    if(str1[i]==str2[i])
        return 0;
    if(str1[i]>str2[i])
        return 1;
    if(str1[i]<str2[i])
        return -1;
return 0;
}
