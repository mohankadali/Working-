#include<stdio.h> 
//int (*fun_ptr[3])();
void fun()
{
    printf("hi i am fun...\n");
}
/*
void mohan()
{
    fun();
    return;
}
void another_fun( int (*fun[3])() )
{
    fun();
    printf("hi  i am another funpointer...\n");

}
*/
int main(void)
{
    int i;
 int  (*fun_ptr[3])() = {fun,fun,fun}; 
    for( i = 0 ; i < 3; i++) {
        fun_ptr[i]();
    }
    //another_fun( fun_ptr  );
    return 0;
}



