void strncp( char* dbuf , char *sbuf , int n ) {  //called function 
    int i;
    for(i = 0 ; i < n ; i++) {
        dbuf[i] = sbuf[i];                          //up to n value it will copy the string
    }
    dbuf[i] = '\0';
}
