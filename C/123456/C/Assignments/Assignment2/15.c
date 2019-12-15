char* insertchar (char *str, const char ch, int pos)    //called function
{
    char buf[100];
    int i;
    int j;
//    int k;
//    int len;

    strcp(buf,str);
    for(i=0;str[i];i++)
    {
        if(i==pos)
        {
            str[i]=ch;
            for(j=i;buf[j];j++)
            {
                str[j+1]=buf[j];  //inserting in to the desired location
            }
        }
    }

    /*    for ( k=0;(str[k]!='\0');k++);
          str[k-1]=str[k];
          for(i=0;str[i];i++)
    {
        if(i==pos)
        {
            for(j=k-1;j>=i;j--)
            {
                str[j]=str[j-1];
            }
            str[i]=ch;
        }
    }
    */
    str[i]='\0';
    return str;
}
