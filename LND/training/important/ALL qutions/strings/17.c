#include<stdio.h>
int main()
{
        char c = 'a';
        char *c_ptr = &c;
        printf("%d & %d",sizeof(char),sizeof c_ptr);
        return 0;
}

