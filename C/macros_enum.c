#include <stdio.h>
#if 0
#define max 10
fun()
{
    printf ("%d", max);
}
int main ()
{
    fun ();
//    #define max 10;// error
//    #define max 10
    printf ("%d", max);
}
#endif
#if 0
#define a b 
#define b c 
#define c a 
int main ( void ) 
{
	int a = 10 ; 
	int b = 20 ; 
	int c = 30 ; 

	printf ("a = %d  b =  %d  c = %d \n" , a ,b, c )  ; 
	return 0 ;
}
#endif 
#if 0
#define MAX 10
int main()
{
char *p = "MAX";
printf("%s",p);
}
#endif
#if 0
struct st{
    char reason;
    enum {
        SCAN,
        AUTH,
        ASSOC,
        CONNECT = 767,
        RUN,
    } state:8;
};
int main() {
    struct st p;
    //struct st p = { 0, RUN};
    printf("%d\n", p.state);
}
#endif
#if 0
#define DPRINTF(x) printf("%s:%d\n",#x,x)
int main()
{
        int ch = 45;
        char balraj;
        DPRINTF(ch);
        return 0;
}
#endif
#if 0
#define MAX (-1u)>>1 
int main()
{
int i;
for (i =31;i>=0; i--)
printf("%d",MAX>>i&1);
return 0;
}
#endif
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
