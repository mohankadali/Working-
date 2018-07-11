#include"header.h"
char sbuf[MAX],dbuf[MAX]; 
int  main()                                             //program starts from here.....    
{
    int option, pos;
    char *p;
    char c, q;

    printf("enter the question number...\n");
    fgets((char*)&option,MAX,stdin);                    //scaning inputsusing fgets
    option = atoi((char*)&option);                      //converting string to integer.
   
    switch (option){
        case 1:
            printf("enter the source string...\n");
            fgets(sbuf,MAX,stdin);
            strcp(dbuf, sbuf);                          //calling function
            printf("destination string =%s\n",dbuf);
            break;
        case 2:
            printf("enter the source string...\n");
            fgets(sbuf,MAX,stdin);
            printf("enter the n value...\n");
            fgets((char*)&option,MAX,stdin);
            option = atoi((char*)&option);
            strncp(dbuf,sbuf,option);
            printf("destination string up to n value =%s\n",dbuf);
            break;
        case 3:
            printf("enter the source string...\n");
            fgets(sbuf,MAX,stdin);
            printf("enter the character.....\n");
            fgets(&c,10,stdin);
            p = chr_add_instr(sbuf,c);
            printf("address of the character=%p\n",p);
            break;
        case 4:
            printf("enter the fisrt string...\n");
            fgets(sbuf,MAX,stdin);
            printf("enter the second string...\n");
            fgets(dbuf,MAX,stdin);
            p = sappend(sbuf,dbuf);
            printf("destination string=%s\n",p);
            break;
        case 5:
            printf("enter the n value...\n");
            fgets((char*)&option,MAX,stdin);
            option = atoi((char*)&option);
            printf("enter the fisrt string...\n");
            fgets(sbuf,MAX,stdin);
            printf("enter the second string...\n");
            fgets(dbuf,MAX,stdin);
            p = snappend(sbuf,dbuf,option);
            printf("destination string=%s\n",p);
            break;
        case 6:
            printf("enter the fisrt string...\n");
            fgets(sbuf,MAX,stdin);
            printf("enter the second string...\n");
            fgets (dbuf,MAX,stdin);
            q = strcm(sbuf,dbuf);
            if(q == 0){
                printf("0\n");}
            else if(q > 0){
                printf("1\n");}
            else{
                printf("-1\n");}
            break;
        case 7:
            printf ("enter the fisrt string...\n");
            fgets (sbuf,MAX,stdin);
            printf ("enter the second string...\n");
            fgets (dbuf,MAX,stdin);
            q=strcasecm (sbuf,dbuf);
            if(q == 0){
                printf ("two strings are equal\n");}
            else if(q > 0){
                printf ("str1 is greater than str2\n");}
            else{
                printf ("str1 is less than str2\n");}
            break;
        case 8:
            printf ("enter the fisrt string...\n");
            fgets (sbuf,MAX,stdin);
            printf ("enter the second string...\n");
            fgets (dbuf,MAX,stdin);
            q = size_tstrspn (sbuf,dbuf);
            printf ("count=%d\n",q);
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
            fgets (sbuf,MAX,stdin);
            q = palindrome (sbuf);
            if (q)
                printf ("yes palindrome\n");
            else
                printf ("not a palindrome\n");
            break;
        case 11:
            printf ("enter the string...\n");
            fgets (sbuf, MAX, stdin);
            p = reverse (sbuf);
            printf ("reversed  string=%s\n",p);
            break;
        case 12:
            printf ("enter the string...\n");
            fgets (sbuf,MAX,stdin);
            p = squeezed (sbuf);
            printf ("squeezed string=%s\n",p);
            break;
        case 13:
            printf ("enter the fisrt string...\n");
            fgets (sbuf,MAX,stdin);
            printf ("enter the second string...\n");
            fgets (dbuf,MAX,stdin);
            q = strrot (sbuf,dbuf);
            if(q)
                printf( "yes rotated string...\n");
            else
                printf ("not a rotated string...\n");
            break;
        case 14:
            printf ("enter the fisrt string...\n");
            fgets (sbuf,MAX,stdin);
            printf ("enter the second string...\n");
            fgets (dbuf,MAX,stdin);
            p = remsstr( sbuf,dbuf);
            printf ("modified string=%s\n",p);
            break;
        case 15:
            printf ("enter the string...\n");
            fgets (sbuf,MAX,stdin);
            printf ("enter the character.....\n");
            fgets (&c,10,stdin);
            printf ("enter the position...\n");
            fgets ((char*)&pos,MAX,stdin);
            pos = atoi ((char*)&pos);
            p = insertchar (sbuf,c,pos);
            printf ("modified string=%s\n",p);
            break;
    }
    return 0;                   //program terminates here....
}
