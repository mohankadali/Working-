#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    ++p;
    printf("p[0] = %d, arr[1] = %d, *p = %d", p[0], arr[1], *p);
    return 0;
}
