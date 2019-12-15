#include <stdio.h>
#if 0
int main()
{
char *p = "MAX";
printf("%s",p);
}
#endif
#if 0
int main()
{
enum x{a = 73.54,b,c,d};
printf("%d\n",d);
return 0;
}
#endif
#if 0
#define x(x) #x
int main()
{
    char a[10]=x(TEL);
    printf("%s\n",a);
}
#endif
#if 0 
int main(void)
{
	enum a {a=10,b,c,d};
	printf("%d\n",a);
	return 0;
}

#endif
#if 0
#define MAX 10
int main(void)
{
	int a ;
	printf("%d",MAX);
	return 0;
}
#endif
#if 0
#define MAX 
int main()
{
        printf("%d\n",MAX); // it will throw an error.
        return 0;
}
#endif
#if 0
#define  aa int
int main(void)
{

aa a  = 100;
printf("%d\n",a);

}
#endif
