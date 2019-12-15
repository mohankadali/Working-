#include <stdio.h>
int myatoi(char *str)
{
    int i,res = 0; 
    for (i = 0 ; str[i] ; ++i)
        res = res * 10 + str [ i ]  - 48 ;
    return res ;
}
int add (int n1 , int n2)
{
    int sum = n1 + n2 ;
    return sum;
}
int sub(int n1,int n2)
{
    int sub=n1-n2;
    return sub;
}
int mul(int n1,int n2)
{
    int mul=n1*n2;
    return mul;
}
int div(int n1,int n2)
{
    int div=n1/n2;
    return div;
}
main (int argc , char **argv)
{
    int result;
    int (*fun_ptr[4]) (int,int) ;
    //printf("enter A=addition\nS=subtration\nM=multiplication\nD=division\n");
    switch (argv[3][0])
    {
        case '+' :  
            fun_ptr[0]=add;
            result = (*fun_ptr[0]) (myatoi(argv[1]) , myatoi(argv[2])) ; 
            printf("sum=%d\n",result);
            break ;
        case '-' :  
            fun_ptr[1]=sub;
            result = (*fun_ptr[1]) (myatoi(argv[1]) , myatoi(argv[2])) ; 
            printf("sub=%d\n",result);
            break ;
        case '*' :  
            fun_ptr[2]=mul;
            result = (*fun_ptr[2]) (myatoi(argv[1]) , myatoi(argv[2])) ; 
            printf("mul=%d\n",result);
            break ;
        case '/' :  
            fun_ptr[3]=div;
            result = (*fun_ptr[3]) (myatoi(argv[1]) , myatoi(argv[2])) ; 
            printf("div=%d\n",result);
            break ;
        default:
            printf("invalid operation..\n");
    }
}
