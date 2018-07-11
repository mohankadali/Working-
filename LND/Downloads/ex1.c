#include <stdio.h>

//  f1 function 
f1()
{
    printf("in f1\n");
}

// f2 function  
f2()
{
    int i = 1;
    printf("in f2\n");
    while(i <= 5)
    {

        if(i == 3) {
            printf ( "i reached value 3\n");
        }

        printf("in f2 ,  i = %d\n", i++);
    }

}

// f3 function
f3(char *ptr)
{
    printf("in f3\n");
    ptr[0] = 'G';
}

// main function 
int main()
{

    char *ptr = "global";

    f1();
    f2();
    f3(ptr);

    printf("after changing %s \n", ptr);


    return 0;

}


