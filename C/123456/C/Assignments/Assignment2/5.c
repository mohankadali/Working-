char * snappend (char *str1, char *str2, int n)            //called function
{
    int i,j;
    for(i=0;str1[i]!='\n';i++);
    str1[i]='\0';
    for(i=0;str2[i]!='\n';i++);
    str2[i]='\0';
    for(i=0;str1[i];i++);
    for(j=0;j<n;j++,i++)
    {
        str1[i]=str2[j];
    }
    return str1;
}
