char * strtokk(char *buf,char *delim)
{           
    int i,j;
    for(i=0;buf[i];i++)
    {
        for(j=0;delim[j];j++)
        {
            if(buf[i]==delim[j])
                buf[i]='\n';
        }
    } 
    return buf;
}                               
