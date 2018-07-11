#include <stdio.h>
struct st{
    int i:8;
    int j:6;
    char ch;
}pq;

void func(void *ptr)
{
    int i;
    char *r = (char *)ptr;

     printf("%d\n", *(r+1));
//    printf("%p\n", (r+1));
}
int main()
{
    struct st pq = {1,2,3};
    func(&pq);
return 0;
}
