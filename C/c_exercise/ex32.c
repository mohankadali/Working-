#include	<stdio.h>
#define SIZE 10
  void size(int arr[SIZE])
  {
          printf("size of array is:%d\n",sizeof(arr));
  }

  int main()
  {
          int arr[SIZE];
          size(arr);
          printf("size of array is:%d\n",sizeof(arr));
          return 0;
  }
