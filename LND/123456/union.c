#include<stdio.h> 
int main(void)
{

    union tag {
    int a;
    char ch[4];
    int b;
    };

    union tag u_tag;
    u_tag.a  = 0;
    u_tag.ch[0]  = 'c';
    u_tag.ch[1]  = 'g';

    printf("%s\n",u_tag.ch);
return 0;
}
