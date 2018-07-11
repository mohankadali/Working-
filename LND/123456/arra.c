#include <stdio.h>
void size(int arr[230]) 
{
    printf("in size %d\n", sizeof(arr));

} 
int main(int b[10], char c[])  

{
    ; 
    void *arr; 
    size(b); 
    printf("in main %d\n", sizeof(b));
    printf("in main %d\n", sizeof(c));
    return 0; 
}
