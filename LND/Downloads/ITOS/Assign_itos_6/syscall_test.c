#include<stdio.h>
#define UNSET 0
int main(void){

     long int ans = syscall(384); //calling the syscall.

     printf("hello global\n");

     if(UNSET == ans){
         
         printf("The my_syscall executed successfully\n");
     
         printf("return value =%ld\n", ans);
     }
     else{
         printf("not executed \n");
     }
     return 0;
}

