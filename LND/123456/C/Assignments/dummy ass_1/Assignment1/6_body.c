#include<stdio.h>

#include"header.h"
unsigned int left_rotate_n_bits ( unsigned int num , int n )
{ 
    int i ;
    for ( i = 0 ; n-- ; i++ )
    {
        if ( num >> 31 & 1 ) 
        {
            num = num << 1 ;
            num = num | 1 ; 
        }
        else
        {
            num = num << 1 ;
        }
        for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- ) 
        {
            printf ( " %d " , num >> i & 1 ) ; 
            if ( (i%8) == 0 )
            {
                printf ( " " ) ;
            }
        }
        printf ( " \n " ) ; 
    }
    return num ;
}
unsigned int right_rotate_n_bits ( unsigned int num , int n ) 
{ 
    int i ;
    for ( i = 0 ; n-- ; i++ ) 
    {
        if ( num >> 0 & 1 ) 
        {
            num = num >> 1 ; 
            num = num | (1 << 31 ) ;
        }
        else
        {
            num = num >> 1 ; 
        }
        for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- )
        {
            printf ( " %d " , num >> i & 1 ) ;
            if ( (i%8) == 0 ) 
            {
                printf ( " " ) ; 
            }
        }
        printf ( " \n " ) ; 
    }
    return num ;
}
unsigned int left_rotate_bits(unsigned int num)
{
    if(num>>(BIT_LENGTH-1)&1)
    {
        num=num<<1;
        num=num|1;
    }
    else
    {
        num=num<<1;
    }
    return num;
}
unsigned int right_rotate_bits(unsigned int num)
{
    if(num>>0&1)
    {
        num=num>>1;
        num=num|(1<<31);
    }
    else
    {
        num=num>>1;
    }
    return num;
}
int rotate ( ) 
{
    int num , result , n , option ;
    printf ( "enter the option 1)left_rotate_n_bits\n2)right_rotate_n_bitsn\n3)left_rotate_bits\n4)right_rotate_bits  \n " ) ; 
    scanf ( "%d" , &option ) ; 
    switch ( option )
    {
        case 1 :
            printf ( "enter the number...\n" ) ; 
            scanf ( "%d" , &num ) ; 
            printf ( "enter the no of bits...\n" ) ; 
            scanf ( "%d" , &n ) ;
            left_rotate_n_bits ( num , n ) ;   
            break ;
        case 2 :
            printf ( "enter the number...\n" ) ; 
            scanf ( "%d" , &num ) ; 
            printf ( "enter the no of bits...\n" ) ; 
            scanf ( "%d" , &n ) ;
            result = right_rotate_n_bits ( num , n ) ; 
            break  ;
        case 3 : 
            printf ( "enter the number...\n" ) ; 
            scanf ( "%d" , &num ) ; 
            printf ( "enter the no of bits...\n" ) ; 
            scanf ( "%d" , &n ) ;
            result = left_rotate_bits ( num ) ;
            break ;
        case 4 :
            printf ( "enter the number...\n" ) ; 
            scanf ( "%d" , &num ) ; 
            printf ( "enter the no of bits...\n" ) ; 
            scanf ( "%d" , &n ) ;
            result = right_rotate_bits ( num ) ; 
            break ;
        default :
            break ;
    }
    return result ;
}
