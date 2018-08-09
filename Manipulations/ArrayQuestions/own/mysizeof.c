#include <stdio.h>

#define mysizeof(X)             \
({                               \
__typeof__(X) y;                \
((char*)(&y+1) - (char*)&y);      \
})
int main()
{
int x;
printf("%d\n",mysizeof("hellobye"));

return 0;
}
