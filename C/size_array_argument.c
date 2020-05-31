#include <stdio.h>
void fun(int ptr[])
{
printf("%d\n",sizeof(ptr));

}
int main()
{

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
printf("%d\n",sizeof(arr));
fun(&arr);

return 0;
}
