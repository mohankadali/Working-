#include"header.h"

int bit_swap1 ( int num , int s , int d ){                      //function definition called function
    int i,j,m,n;
    for ( i = 0 ; i < BIT_LENGTH ; i++ ){
        for ( j = BIT_LENGTH-1 ; j >= 0 ; j--){
            if ( i == s && j == d ){
                m = num >> i & 1;
                n = num >> j & 1;
                if ( m != n ){
                    num = num ^ ( 1 << i ) ;
                    num = num ^ ( 1 << j ) ;
                } 
            }
        }
    }
    return num;
}
int ass_1 ( void ){
    int num , source , dest , result ;

    printf ( "enter the number...\n " ) ;
//    fgets((char*)&num,MAX,stdin);
  //  num=atoi((char*)&num);

    scanf ( "%d" , &num ) ;
    printf ( "enter the source,destination positions.....\n " ) ;
    scanf ( "%d%d" , &source , &dest ) ;
    result = bit_swap1 ( num , source , dest ) ;                 // calling function
    return result ;
}
