#include <stdio.h>
void size(int arr[10]) 
{
        printf("in size %d\t", sizeof(arr));

} 
int main() 

{
        int arr[10];
    //    void *arr; 
        size(arr); 
        printf("in main %d\n", sizeof(arr));
        return 0; 
}
