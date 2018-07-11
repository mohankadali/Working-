#include"header.h"
int even_bit_toggle ( int num ){                               //called function
    int i ;
    for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- ){                    //loop for toggling even bits
        if ( i%2 == 0 ){
            num = num ^ ( 1 << i ) ; 
        }
    }
    return num ;
}
int odd_bit_toggle ( int num ){
    int i ;
    for ( i = BIT_LENGTH-1 ; i > 0 ; i = i - 2 ){               //loop for toggle the odd bits
        num = num ^ ( 1 << i ) ; 
    }
    return num ;
}
int toggle ( ) {
    int num , result ;
    int option ;
    printf ( "enter the option 1)even bit toggle 2)odd bit toggle....\n" ) ; 
    scanf ( " %d " , &option ) ; 
    switch ( option ){
        case 1 :
            printf ( "enter the number....\n " ) ;
            scanf ( "%d" , &num ) ; 
            result = even_bit_toggle ( num ) ;                  //calling function 
            break ;
        case 2 :
            printf ( "enter the number....\n " ) ; 
            scanf ( "%d" , &num ) ; 
            result = odd_bit_toggle ( num ) ;                   //calling function
            break ;
        default : break ;
    }
    return result ;
}
