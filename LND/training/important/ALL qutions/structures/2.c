struct tag{
    short s:9;
    int j:9;
    //  char c;
    short t:9;
    //  short u:9;
        char d;
}A;






struct st{
    int c;
     //  char d;
     //  short abc :8;
     //  short q :2;
     // short abcd:8;
     // char e;
     char u;
    int  :0;
     char v;
}B;
main()
{
//    printf("%d\n",sizeof(A));
printf("%d\n",sizeof(B));
}
