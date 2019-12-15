int size_tstrspn(const char *buf1,const char *buf2) //called function 
{
    int i,j,c=0;
    char ch;
    for(j=0;buf1[j];j++)
    {        
        ch=buf1[j];
        for(i=0;buf2[i];i++)
        {
            if(ch==buf2[i])             //counting intial set of characters
            {
                c++;
                break;
            }
        }
    }
    c--;
    return c;
}
