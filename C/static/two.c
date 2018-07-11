 #include<stdio.h>
extern int i; //Declaration of variable i.
extern int j; //Declaration of variable j.
/**
Above two lines will search the initialization statement of variable i and j
either in two.c (if initialized variable is static or extern) or one.c (if
initialized variable is extern) 
*/
//extern void sum(){
void sum(){
    int s;
    s=i+j;
    printf("%d",s);
}
