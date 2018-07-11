#include<stdio.h> 
#include<stdlib.h>
#include"header.h"
#define MAX 100
int  main()
{
    int option,result;
    printf("enter the question number...\n");
    fgets((char*)&option,MAX,stdin);
    option=atoi((char*)&option);
    switch(option)
    {
        case 1:
            result=q1_a();
            printf("%d\t",result);
           result=q1_b();
            printf("%d\t",result);
           result=q1_c();
            printf("%d\t",result);

            break;
        case 2:
            q2();
            break;
        case 3:
            q3();
            break;
    }
}
