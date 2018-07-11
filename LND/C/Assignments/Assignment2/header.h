#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void str_cpy (char*, char*);
void strn_cpy (char*, char*, int);
int char_addr_instr (char*, char);
void str_append (char *, char *);
void strn_append (char *, char *, int);
int str_len (char *);
int str_cmp (char *, char *);
int str_case_cmp (char *, char *);
int make_lo_case (char*);
int str_spn (char *, char *);
int str_palindrm (char *);
char str_rev (char *, char *);
void str_squeeze (char *);
int str_rot (char *, char *);
char *remsstr (char *, char *);
char insert_char (char * , char , int);
