#include<stdio.h> 
#include"header.h" 

int bit_swap3 ( int snum , int s , int dnum , int d , int num )
{
    int i , j , m , n ;                                                                
    for ( i = s , j = d ; num-- ; i-- , j-- )
    {        
        m = snum >> i & 1 ;                                                      
        n = dnum >> j & 1 ;                                                     
        if ( m != n )                                                         
        {                                                               
            dnum = dnum ^ ( 1 << j ) ;                                              
        }
    }                                                               

    /*    printf("\n");
          for(i=31;i>=0;i--)
          {
          printf("%d",dnum>>i&1);
          }*/
    return dnum ;
}
int ass_3 ( void )
{
    int snum , s , dnum , d , result , n ; 
    printf ( "enter the snumber dnumber.....\n" ) ; 
    scanf ( "%d%d" , &snum , &dnum ) ;
    printf ( "enter the s,d,n .....\n " ) ; 
    scanf ( "%d%d%d" , &s , &d , &n ) ; 
    result = bit_swap3 ( snum , s , dnum , d , n ) ; 
    return result ;  
}
