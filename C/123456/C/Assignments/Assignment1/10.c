#include"header.h"
int bit_swap10 ( int x , int p , int num , int y ){             // called function......
    int i , j , m , n ;                                                                
    for ( i = p , j = num - 1 ; num-- ; i-- , j-- ) {           // loop used for set right most n bits  
        m = y >> i & 1 ;                                                     
        n = x >> j & 1 ;                                                      
        if ( m != n ){                                                               
            x = x ^ ( 1 << j ) ;                                             
        }
    }                                                               
    return x ;
}
int ass_10 ( void ){
    int x , p , n , y , result ;
    printf ( "enter the x,y .....\n " ) ;
    scanf ( "%d%d" , &x , &y ) ; 
    printf ( "enter the p,n .....\n " ) ; 
    scanf ( "%d%d" , &p , &n ) ; 
    result = bit_swap10 (x , p , n , y ) ;                      //calling function
    return result ; 
}



