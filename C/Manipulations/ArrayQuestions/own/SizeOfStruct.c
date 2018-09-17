#include <stdio.h>
struct st{

        int x;
        char y;
        float f;
}ST[2];
int main()
{
        int f,l;
        f= &ST[1].x;
        l= &ST[0].x;

        printf("%d  \n",f-l);
        return 0;
}
