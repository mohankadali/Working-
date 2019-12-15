char *remsstr(char *s1, char *s2)   //called function
{
    int i,j,temp;
    for(i=0;s1[i]!='\n';i++);
    s1[i]='\0';
    for(i=0;s2[i]!='\n';i++);
    s2[i]='\0';
    for(i=0;s1[i];i++){
        if(s2[0]==s1[i]){
            for(j=0;s2[j];j++){
                temp=i;
                if(s1[i]==s2[j]){
                    for(i=i;s1[i];i++)
                        s1[i]=s1[i+1];      //removing the substring
                    i=temp;
                }
                else
                {
                    s1[i]='\0';
                    break;
                }
            }
        }
    }
    return s1;
}
