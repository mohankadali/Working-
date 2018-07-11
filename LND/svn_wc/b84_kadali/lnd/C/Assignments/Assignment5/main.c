#include<stdio.h> 
#include<stdlib.h>
#include"header.h"
#define MAX 100
char dbuf[100],sbuf[100]; 
int  main()
{
    int option,pos;
    char *p;
    char c,q;

    printf("enter the question number...\n");
    fgets((char*)&option,MAX,stdin);
    option=atoi((char*)&option);
    switch(option)
    {
        case 1:
            question1();
            break;
        case 2:
            question2();
            break;
        case 3:
            question3();
            break;
        case 4:
            question4();
            break;
        case 5:
            question5();
            break;
        case 6:
            question6();
            break;
    }
}
