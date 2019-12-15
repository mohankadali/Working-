char * squeezed(char * str)     //called function
{

    int i,j,l,l1;
    for(l=0 ; str[l] ; l++);
    l1=0;
    for( i=0 ; i < (l-l1) ; ) 
    {
        if(str[i]==str[i+1])
        {
            for(j=i;j<(l-l1);j++)
                str[j]=str[j+1];    //removing the repeated character
            l1++;
        }
        else
        {
            i++;
        }
    }
    return str;
}
