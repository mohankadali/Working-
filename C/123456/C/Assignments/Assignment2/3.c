char * chr_add_instr (char *sbuf, char c){ // called function
    int i;
    for(i = 0 ; sbuf[i] ; i++) { 
        if(sbuf[i] == c)
            return sbuf + i ;               //return the address of first occurence of character
    }
    return 0;
}
