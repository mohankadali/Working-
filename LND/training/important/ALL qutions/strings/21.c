#include<stdio.h> 
int main() 
{ 
        char *src = "Hi"; 
        char *dest = "Hello"; 
        dest = src; 
        printf("%s\n", src); 
        return 0; 
}
