#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);

int main(int argc, char *argv[])
{

    int a = 2;
    int b = 3;

    int result ;



    a = atoi(argv[1]);
    b = atoi(argv[2]);
    result = add(a, b);
    printf("result = %d\n", result);


    return 0;

}


int add(int a, int b)
{
    return (a + b);
}

