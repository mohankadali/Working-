#include<stdio.h>

int a;            // before linking Common after Linking .bss

int b = 1;        // .data

static int n = 0;     //.bss

static int c;         // .bss

static int d = 2;     //.data

const int l = 0;       //.rodata
const int l1;           //.bss

const int m = 3;        // .rodata

static const int p;     //.bss

static const int g = 4;   //.rodata

static const int f = 0;   //.rodata

volatile int v ;          // .bss

volatile int u = 12 ;      //.data

volatile const int q;      //.bss

volatile const int r1 = 8;  //.data
 
volatile const int x1 = 0;  //.data

const volatile int q;       //.bss

const volatile int r = 8;    //.data

const volatile int x = 0;    //.data

volatile static int y;        //.bss

volatile static  int z = 20;   //.data

volatile static const int w = 12; //.data

static volatile const int h = 0;  //.data

int main(void){
    /*
       int a;                  // stack

       int b = 1;              // stack

       static int n = 0;       //.bss

       static int c;            // .bss

       static int d = 2;         //.data

       const int l = 0;          //stack

       const int m = 3;           // stack

       static const int p;        //.bss

       static const int g = 4;      //.rodata

       static const int f = 0;       //.rodata

       volatile int v ;         // .stack

       volatile int u = 12 ;            //stack

       volatile const int q;         //stack

       volatile const int r = 8;        //stack

       volatile const int x = 0;        //stack

       const volatile int q1;        //stack

       const volatile int r1 = 8;       //stack

       const volatile int x1 = 0;       //stack

       volatile static int y1;          //.bss

       volatile static  int z = 20;         //.data
       const volatile static int w = 12;    ////.data

       static   int h;                      //.bss
       static int h1 =0;                    //.bss 
       static volatile   int h2;            //.bss
       static volatile int h3 =0;           //.bss
       static volatile  const int h4;       //.bss
       static volatile const  int h5 =0;       //.data

       return 0;*/
}
