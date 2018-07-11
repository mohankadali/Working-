#include"header.h"                      // including prototype of the functions
int main( )                              // main starts from here     
{
    int (*fun_ptr[12]) ();
    int result, i, qstn ;
    printf ( "enter the question number(1 to 12)....\n" ) ;
    scanf ( "%d", &qstn ) ;
    int n, p ;
    int x, pos, num ;
    int num1, num2, num3, s, d ;
    switch (qstn){
        case 1 :
            fun_ptr[0] = ass_1;
            result = (*fun_ptr[0])();                     // calling function    
            break ; 
        case 2 :
            fun_ptr[1] = ass_2;
            result = (*fun_ptr[1])();                     // calling function    
            break ; 
        case 3 :
            fun_ptr[2] = ass_3;
            result = (*fun_ptr[2])();                     // calling function    
            break ; 
        case 4 :
            fun_ptr[3] = toggle;
            result = (*fun_ptr[3])();                     // calling function    
            break ;
        case 5 :
            printf ( "enter the number,position...\n " ) ;
            scanf ( "%d%d" , &n , &p ) ;
            result=bit_ts(n,p);
    break ; 
        case 6 :
            fun_ptr[5] = rotate;
            result = (*fun_ptr[5])();                     // calling function    
            break ; 
        case 7 :
            fun_ptr[6] = count;
            result = (*fun_ptr[6])();                     // calling function    
           printf("count=%d\n",result);
            break; 
        case 8 :
            fun_ptr[7] = leading;
            result = (*fun_ptr[7])();                     // calling function    
           printf("count=%d\n",result);
            break ;   
        case 9:
            printf("enter numbers 1,2,3 and source and destination bits\n");
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
            fun_ptr[9] = ass_10;
            result = (*fun_ptr[9])();                     // calling function    
            break ; 
        case 11 :
            fun_ptr[10] = ass_11;
            result = (*fun_ptr[10])();                     // calling function    
            break ; 
        case 12 :
            printf ( "enter the x value,position bit,num value...\n " ) ; 
            scanf ( "%d%d%d" , &x , &pos , &num ) ;
            result = left_adjusted ( x , pos , num ) ;
            break ; 
        default :
            break ;
    }
    for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- ){
        printf ( "%d" , result >> i & 1 ) ;        
        if ( i % 8 == 0 ) 
            printf ( " " ) ;
    }
    return 0;
}

