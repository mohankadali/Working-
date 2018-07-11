#include"header.h"
int bit_swap3 ( int snum , int s , int dnum , int d , int num ){   //called function
    int i , j , m , n ;                                                                
    for ( i = s , j = d ; num-- ; i-- , j-- ){                      //loop used for copies the n right adjusted bits 
        m = snum >> i & 1 ;                                                      
        n = dnum >> j & 1 ;                                                     
        if ( m != n ){                                                               
            dnum = dnum ^ ( 1 << j ) ;                                              
        }
    }                                                               
    return dnum ;
}
int ass_3 ( void ){     
    int snum , s , dnum , d , result , n ; 
    printf ( "enter the snumber dnumber.....\n" ) ; 
    scanf ( "%d%d" , &snum , &dnum ) ;
    printf ( "enter the s,d,n .....\n " ) ; 
    scanf ( "%d%d%d" , &s , &d , &n ) ; 
    result = bit_swap3 ( snum , s , dnum , d , n ) ;                //calling function
    return result ;  
}
