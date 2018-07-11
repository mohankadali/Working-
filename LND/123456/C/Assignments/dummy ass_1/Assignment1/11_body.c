#include<stdio.h>
#include"header.h"
int invert ( int x , int p , int num )
{
    int i  ;                                                                
    for ( i =  p ; num-- ; i-- ) 
    {        
        x = x ^ ( 1 << i ) ;                                              
    }
return x ;
}
int ass_11 ( ) 
{
    int result , x ,  p , num ;
    printf ( "enter the x value,position bit,num value...\n " ) ; 
    scanf ( "%d%d%d" , &x , &p , &num ) ; 
    result = invert ( x , p , num ) ; 
    return result ;
} 
