#include<stdio.h>
#include"header.h"                      // including prototype of the functions
int main ( )                              // main starts from here     
{
    int result , i , qstn ;
    printf ( "enter the question number(1 to 12)....\n" ) ;
    scanf ( "%d" , &qstn ) ;
    int n , p ;
    int x , pos , num ;
            int num1,num2,num3,s,d;

    switch(qstn)
    {
        case 1 :
            result = ass_1 ( ) ;                     // calling function    
            break ; 
        case 2 :
            result = ass_2 ( ) ;                     // calling function    
            break ; 
        case 3 :
            result = ass_3 ( ) ;                     // calling function    
            break ; 
        case 4 :
            result = toggle ( ) ;                     // calling function    
            break ;
        case 5 :
            printf ( "enter the number,position...\n " ) ;
            scanf ( " %d%d " , &n , &p ) ;
            result = bit_ts ( n , p ) ;
            break ; 
        case 6 :
            result = rotate ( ) ;                     // calling function    
            break ; 
        case 7 :
            result = count ( ) ;                     // calling function    
            break; 
        case 8 :
            result = leading ( ) ;                     // calling function    
            break ;   
        case 9:
            printf("enter numbers, num and source and destination bits\n");
            scanf("%d%d%x%d%d",&num1,&num2,&num3,&s,&d);
            max_min_nums(num1,num2);
            clear_rightmost_set(num3);
            set_rightmost_clear(num3);
            clear_leftmost_set(num3);
            set_leftmost_clear(num3);
            set_range_bits(num3,s,d);
            clear_range_bits(num3,s,d);
            toggle_range_bits(num3,s,d);
            break; 

        case 10 :
            result = ass_10 ( ) ;                     // calling function    
            break ; 
        case 11 :
            result = ass_11 ( ) ;                     // calling function    
            break ; 
        case 12 :
            printf ( "enter the x value,position bit,num value...\n " ) ; 
            scanf ( "%d%d%d" , &x , &pos , &num ) ;
            result = left_adjusted ( x , pos , num ) ;
            break ; 
        default :
            break ;
    }
    for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- )                 
    {
        printf ( "%d" , result >> i & 1 ) ;        
        if ( i % 8 == 0 ) 
            printf ( " " ) ;
    }
    return 0;
}
