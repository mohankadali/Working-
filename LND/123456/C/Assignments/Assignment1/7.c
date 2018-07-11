#include"header.h"
int count_bit_set(int num){                                 //  called function 
    int i , c = 0 ;
    for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- ) {
        if ( ( num >> i & 1 ) == 1 ) 
            c++ ;
    }
    return c ;
}
int count_bit_clear(int num){                               //called function
    int i , c = 0 ;
    for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- ) {
        if ( ( num >> i & 1 ) == 0 ) 
            c++ ;
    }
    return c ;
}
int count ( void ){
    int num , result , option ;
    printf ( "enter the option 1)count bit set 2)count bit clear...\n" ) ; 
    scanf ( "%d" , &option ) ; 
    switch ( option ) {
        case 1 : 
            printf ( "enter the n umber...\n" ) ; 
            scanf ( "%d" , &num ) ; 
            result = count_bit_set ( num ) ;                //calling function
            break ;
        case 2 :
            printf ( "enter the n umber...\n" ) ; 
            scanf ( "%d", &num ) ; 
            result = count_bit_clear ( num ) ;
            break ;
        default :   break ;
    }
    return result ;
}
