#include<stdio.h>
#define BIT_LENGTH (sizeof(int)*8)


int bit_swap1 ( int , int , int ) ;
int ass_1 ( void ) ; 
            

int bit_swap2 ( int , int , int , int ) ;
int ass_2 ( void ) ;
            

int bit_swap3 ( int , int , int , int , int  ) ; 
int ass_3 ( void ) ; 
            

int even_bit_toggle ( int ) ; 
int odd_bit_toggle ( int ) ; 
int toggle ( ) ; 
            
            
            
unsigned int left_rotate_n_bits ( unsigned int , int ) ; 
unsigned int right_rotate_n_bits(unsigned int , int ) ;
unsigned int left_rotate_bits ( unsigned int  ) ; 
unsigned int right_rotate_bits ( unsigned int ) ;
int rotate ( ) ; 
            

int count_bit_set ( int ) ; 
int count_bit_clear ( int ) ;
int count ( void ) ;

            

int cnt_trailing_cleared_bits ( int ) ; 
int cnt_trailing_set_bits ( int  ) ;
int cnt_leading_set_bits ( int  ) ; 
int cnt_leading_cleared_bits ( int  ) ;
int leading ( ) ; 
            
           
int bit_swap10 ( int  , int , int , int  ) ;
int ass_10 ( void ) ;


int invert ( int ,int ,int ) ; 
int ass_11 ( ) ; 







#define max_min_nums(num1,num2) {int temp;\
    temp=num1-num2;\
    temp=(temp>>31)&1;\
    if(temp)\
    {\
        printf("max is %d\n",num2);\
    }\
    else\
    {\
        printf("max is %d\n",num1);\
    }\
}
#define clear_rightmost_set(num) {int temp;\
    temp=num;\
    (temp=(temp&(temp-1)));\
    printf("after clearing rightmost set bit num is %x\n",temp);\
}
#define set_rightmost_clear(num) {int temp;\
    temp=num;\
    (temp=temp|(temp-1));\
    printf("after setting rightmost clear bi num is %x\n",temp);\
}
#define clear_leftmost_set(num) { int temp,ref;\
    ref=num;\
    for(temp=31;temp>=0;temp--) {\
        if((ref>>temp)&1){\
            ref=ref&~(1<<temp);\
            break;\
        }\
    }\
    printf("after clearing leftmost set bit num is %x\n",ref);\
}
#define set_leftmost_clear(num) { int temp,ref;\
    ref=num;\
    for(temp=31;temp>=0;temp--) {\
        if(!((ref>>temp)&1)){\
            ref=ref^(1<<temp);\
            break;\
        }\
    }\
    printf("after setting leftmost clear bit num is %x\n",ref);\
}
#define set_range_bits(num,s,d) { int  temp,ref;\
    ref=num;\
    ref=0;\
    for(temp=s;temp>=d;temp--) {\
        ref=ref|(1<<temp);\
    }\
    printf("after setting bits from sourse to dest position num is %x\n",ref);\
}
#define clear_range_bits(num,s,d) { int temp,ref;\
    ref=num;\
    ref=~0;\
    for(temp=s;temp>=d;temp--) {\
        ref=ref^(1<<temp);\
    }\
    printf("after clearing bits from source to dest position num is %x\n",ref);\
}
#define toggle_range_bits(num,s,d) { int temp,ref;\
    ref=num;\
    for(temp=s;temp>=d;temp--) {\
        ref=ref^(1<<temp);\
    }\
    printf("after toggling bits from source to dest position num is %x\n",ref);\
}











#define left_adjusted(x,p,n) (x>>(p))& ~(~0<<n)                                
#define bit_ts(num,pos) (num>>pos&1)?(printf("no need set...\n")):(num=num|1<<pos)



