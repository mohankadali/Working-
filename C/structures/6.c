#include       <stdio.h> 
int main() 
{ 
    struct abc { 
        int x; 
        int y; 
        int z; 
    } ;
    struct abc v = {1, 2, 3}; 
    struct abc *ptr = &v; 
    printf("%d ", v.x); 
    printf("%d ", ptr->z); 
    printf("%d ", (*ptr).z); 
}
