void strcp ( char *dbuf , char *sbuf) {  //called function 
    while( *sbuf != '\0' ) {             //loop rotate till the null termination   
        *dbuf++ = *sbuf++;
    }
    *dbuf = '\0';   
}
