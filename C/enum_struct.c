#include <stdio.h>

struct ST {

        enum {MODE1=5, MODE2,MODE3} mode;
        enum {TYPE1,TYPE2} type;

};
void fun(struct ST *ptr){

ptr -> mode = MODE1;

}

int main()
{
        struct ST *ptr = (struct ST*)malloc(sizeof(struct ST));
        fun(ptr);
        printf("%d\n", ptr -> mode);
        return 0;
}

