#include"header.h" 
int strrot(char *str,char *rstr)
{
    int i,j;
    for(i=0;str[i]!='\n';i++);
    str[i]='\0';
    for(i=0;rstr[i]!='\n';i++);
    rstr[i]='\0';
    char buf[100];
    strcp(buf,str);



    for(i=0;str[i];i++);
    for(j=0,i=i;str[j];j++,i++)
    {
        str[i]=buf[j];
    }
    str[i]='\0';



    if(strstr(str,rstr))
        return 1;
    else
        return 0;
    return 0;    
}

