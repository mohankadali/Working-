/* gcc -pg file  name
 * run a.out 
 * creates gmon.out
 * gprof -b a.out gmon.out
*/
#include<stdio.h>
void fun()
{ 
int     i =0;
    while (i < 100000000)
    {
        i = i+1;
    }
}
int main(void)
{

    fun();

    return 0;
}

