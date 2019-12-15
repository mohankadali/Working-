#include"header.h"
int bit_swap2 ( int snum , int s , int dnum , int d ){   //called function   
    int i , j , m , n ;                                                                
    i=snum>>s&1;
    j=dnum>>d&1;
    if(i != j){
        snum=snum^(1<<s);                               //comlimenting the bit position
        dnum=dnum^(1<<d);
    }
    for ( i=BIT_LENGTH-1 ; i >= 0 ; i-- ){
        printf ( "%d" , snum >> i & 1 ) ;
        if ( i % 8 == 0 )
            printf ( " " ) ;
    }
    printf ( "\n" ) ;
    return dnum ;
}
int ass_2 ( void ){
    int snum , s , dnum , d , result ;
    printf ( "enter the snumber dnumber.....\n" ) ; 
    scanf ( "%d%d" , & snum , &dnum ) ;
    printf ( " enter the sbit dbit.....\n " ) ; 
    scanf ( "%d%d" , &s , &d ) ;
    result = bit_swap2 ( snum , s , dnum , d ) ;       //calling function     
    return result ;
}
