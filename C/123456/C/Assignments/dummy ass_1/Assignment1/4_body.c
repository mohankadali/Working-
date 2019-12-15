#include<stdio.h> 
#include"header.h"
int even_bit_toggle ( int num )
{
    int i ;
    //  for(i=30;i>=0;i=i-2)
    for ( i = BIT_LENGTH-1 ; i >= 0 ; i-- )
    {
        if ( i%2 == 0 )
        {
            num = num ^ ( 1 << i ) ; 
        }
    }
    return num ;

}
int odd_bit_toggle ( int num )
{
    int i ;
    for ( i = BIT_LENGTH-1 ; i > 0 ; i = i - 2 )
    {
        num = num ^ ( 1 << i ) ; 
    }
    return num ;

}
int toggle ( ) 
{
    int num , result ;
    int option ;
    printf ( "enter the option 1)even bit toggle 2)odd bit toggle....\n" ) ; 
    scanf ( " %d " , &option ) ; 
    switch ( option )
    {
        case 1 :
            printf ( "enter the number....\n " ) ;
            scanf ( "%d" , &num ) ; 
            result = even_bit_toggle ( num ) ; 
            /*    for(i=31;i>=0;i--)
                  {
                  printf("%d",eve>>i&1);
                  }
                  printf("\n");*/
            break ;
        case 2 :

            printf ( "enter the number....\n " ) ; 
            scanf ( "%d" , &num ) ; 
            result = odd_bit_toggle ( num ) ;
            /*           for(i=31;i>=0;i--)
                         {
                         printf("%d",odd>>i&1);
                         } 
                         printf("\n");*/
            break ;
        default :
            break ;
    }
    return result ;
}
