#include<stdio.h> 
#include"header.h"


int bit_swap2 ( int snum , int s , int dnum , int d )
{
    int i , j , m , n ;                                                                
    for ( i = 0 ; i < BIT_LENGTH-1 ; i++ )                                              
    {                                                                           
        for ( j = BIT_LENGTH-1 ; j > 0 ; j-- )                                          
        {                                                                       
            if ( i == s && j == d )                                                    
            {                                                                   
                m = snum >> i & 1 ;                                                      
                n = dnum >> j & 1 ;                                                      
                if ( m != n )                                                        
                {                                                               
                    snum = snum ^ ( 1 << i ) ;                                             
                    dnum = dnum ^ ( 1 << j ) ;                                             
                }
            }                                                               
        }                                                                   
    }                                                                       
    for ( i=BIT_LENGTH-1 ; i >= 0 ; i-- )
    {
        printf ( " %d " , snum >> i & 1 ) ;
        if ( i % 8 == 0 )
            printf ( " " ) ;
    }
    printf ( " \n " ) ;
    return dnum ;
}
int ass_2 ( void )
{
    int snum , s , dnum , d , result ;
    printf ( "enter the snumber dnumber.....\n" ) ; 
    scanf ( "%d%d" , & snum , &dnum ) ;
    printf ( " enter the sbit dbit.....\n " ) ; 
    scanf ( "%d%d" , &s , &d ) ;
    result = bit_swap2 ( snum , s , dnum , d ) ;
    return result ;
}
