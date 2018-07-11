#include<stdio.h> 
#include"header.h"
#define MAX 100

char sbuff[MAX], dbuff[MAX], rev[MAX]; 

int  main ()
{
    int option, n, pos, s_len, d_len;
    char *p;
    int	r;
    char c, q;
	printf("\n1:srtcpy\t2:strncpy\t3:char_address\t4:strappend\t5:strnappend\t6:strcmp\t7:str_case_cmp\t8:strspn\t10:str_palindrm\t11:strrev\t12:str_squeeze\t13:str_rot\t14:str_remsstr\t15:insert_char\n");
    printf ("enter the question number...\n");
    fgets ((char*)&option, MAX, stdin);
    option = atoi ((char*)&option);
    switch (option)
    {
        case 1:
            printf ("enter the source string...\n");
            fgets (sbuff, MAX, stdin);
            str_cpy (dbuff, sbuff);
            printf ("destination string =%s\n", dbuff);
            break;
        case 2:
            printf ("enter the source string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the n value...\n");
            fgets ((char*)&n,MAX,stdin);
            n = atoi ((char*)&n);
            strn_cpy (dbuff, sbuff, n);
            printf ("destination string up to n value =%s\n", dbuff);
            break;
        case 3:
            printf ("enter the source string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the character.....\n");
            fgets (&c, 10, stdin);
            r = char_addr_instr (sbuff, c);
            printf ("address of the character=%p\n", sbuff+r);
            break;
        case 4:
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
            str_append (sbuff, dbuff);
            printf ("destination string=%s\n", dbuff);
            break;
        case 5:
            printf ("enter the n value...\n");
            fgets ((char*)&n, MAX, stdin);
            n = atoi ((char*)&n);
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
            strn_append (sbuff, dbuff, n);
            printf ("destination string=%s\n", dbuff);
            break;
        case 6:
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
			s_len = str_len (sbuff);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
			d_len = str_len (dbuff);
			if ((s_len) = (d_len)) {
            	q = str_cmp (sbuff, dbuff);
				printf ("%d\n", q);
			}
	  		if ((s_len) > (d_len))
				printf ("1\n");
			else if (s_len < d_len)
				printf ("-1\n");
			break;
        case 7:
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
			s_len = str_len (sbuff);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
			d_len = str_len (dbuff);
			if ((s_len) = (d_len)) {
            	q = str_case_cmp (sbuff, dbuff);
				printf ("%d\n", q);
			}
	  		if ((s_len) > (d_len))
				printf ("1\n");
			else if (s_len < d_len)
				printf ("-1\n");
            break;
        case 8:
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
            q = str_spn (sbuff, dbuff);
            printf ("count=%d\n", q);
            break;
            /*        case 9:
                      printf("enter the buf string...\n");
                      fgets(sbuf,MAX,stdin);
                      printf("enter the delim string...\n");
                      fgets(dbuf,MAX,stdin);
                      p=strtokk(sbuf,dbuf);
                      printf("strtok'ed  string=\n%s",p);
                      break;   */
        case 10:
            printf ("enter the string...\n");
            fgets (sbuff, MAX, stdin);
            q = str_palindrm (sbuff);
            if (q)
                printf ("yes palindrome\n");
            else
                printf( "not a palindrome\n");
            break;
        case 11:
            printf ("enter the string...\n");
            fgets (sbuff, MAX, stdin);
            str_rev (sbuff, rev);
            printf ("reversed  string=%s\n", rev);
            break;
        case 12:
            printf ("enter the string...\n");
            fgets (sbuff, MAX, stdin);
            str_squeeze (sbuff);
            printf ("squeezed string=%s\n", sbuff);
            break;
        case 13:
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
            q = str_rot( sbuff, dbuff);
            if (q)
                printf ("yes rotated string...\n");
            else
                printf ("not a rotated string...\n");
            break;
        case 14:
            printf ("enter the fisrt string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the second string...\n");
            fgets (dbuff, MAX, stdin);
            p = remsstr (sbuff, dbuff);
            printf ("modified string=%s\n",p);
            break;
        case 15:
            printf ("enter the string...\n");
            fgets (sbuff, MAX, stdin);
            printf ("enter the character.....\n");
            fgets (&c, 10, stdin);
            printf ("enter the position...\n");
            fgets ((char*)&pos, MAX, stdin);
            pos = atoi ((char*)&pos);
            insert_char (sbuff, c, pos);
            printf ("modified string=%s\n", sbuff);
            break;
    }
    return 0;
}
