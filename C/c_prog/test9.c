#include<stdio.h>
void f1(){
    extern int g;
    static int s=5;
    int a;
    ++g;
    a=s++;
    printf("%d%d%d",a,s,g);
    if(a<=6)
        f1();
    printf("%d%d%d",a,s,g);
}
void f2(){
    static int s;
    int a;
    a=++s;
    ++g;    
    printf("%d%d%d",a,s,g);
    if(a<=2)
        f2();
    printf("%d%d%d",a,s,g);
}
main(){
    f1();   
    f2();
}
