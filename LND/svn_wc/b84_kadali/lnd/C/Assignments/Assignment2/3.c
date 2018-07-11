

char * chr_add_instr (char *sbuf, char c){ // called function
    int i;
    for(i = 0 ; sbuf[i] ; i++) { 
        if(sbuf[i] == c)
        {
            printf("%p\n",(sbuf+i));
            return sbuf + i ;               //return the address of first occurence of character
        }
    }
    return 0;
}
