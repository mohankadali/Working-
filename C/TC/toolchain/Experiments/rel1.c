#include<stdio.h>                                
extern int ex;                  //             
int A,B,C;                      //.Bss(executable file)   //.comment(relocatable file) 
int D=12;                       //.data
int E=20;                       //.data
static int F,G,H;               //.Bss    
static int I=92;                //.data    
static int J=29;                //.data
const int M=88;                 //.rodata
const static int ABC;                 //.bss
extern void add(int,int);           
//static void add(int,int);           
int main(void)              
{                       
    static int mn=24;                //.data 
    static int op;                   //.bss 
   const static int pq=24;           //.rodata 
   const static int rs;              //.bss 
    A=34;           
    B=19;   
    C=29;
    F=62;
    G=26;
    H=18;
    add(2,9);               //
    ex=10;
    printf("ex=%d\n",ex);
}












