#include <stdio.h>
#if 0
#endif
#if 0
#endif
#if 0
int main()
{
        char str[]="Sonyjkg is  Japanese based company" ;
        printf("%s\n",str);
        char *tmp,*s;
        tmp=str;
        printf("%s\n",tmp);
        s=strstr(str,"Japanese ");
        printf("%p %p\n",&tmp, &s);
        strcat(tmp,s);
        printf("%s",s);
}
#endif
#if 0
int main()
{
        char *src = "Hi";
        char *dest = "Hello";
        dest = src;
        printf("%s\n", src);
        printf("%s\n", dest);
        return 0;
}
#endif
#if 0
int main ( )
{
        char str[]="Hello\0world";
        printf("%d %d", sizeof(str), strlen(str));
        return 0;
}
#endif
#if 0
int main() {
        char *str = "Hello World";
        *str = 'h';
        printf("%s", str);
}
#endif
#if 0
har s[] = "Global";
int main(void)
{
        strcpy (s, "Edge");
        printf("%s\n",s);
        return 0;
}
#endif
#if 0
int main()
{
        char *ptr="Hello"
                "\0"
                "world";
        printf("%s",ptr);
}
#endif
#if 0
int main(void)
{
        char p[] = "hello world";

        char b[10],c[10];

        int i,j;
        for(i= 0;p[i];i++);
        i=i-1;
        for(j=0;i>j;j++,i--)
        {
                p[i]^=p[j]^=p[i]^=p[j];

        }
        fwrite( p, 15, 1, stdout);
        printf("%s\n",p);
}

#endif
#if 0
char b[2] = "tata"; // will give a warning array of chars is too long 
int main()
{

char a[2] = "hello"; // will give a warning array of chars is too long 
printf("%s\n",a);
printf("%s\n",b);

return 0;
}
#endif
