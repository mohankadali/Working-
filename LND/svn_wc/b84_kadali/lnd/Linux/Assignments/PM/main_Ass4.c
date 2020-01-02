
/*program to understand the shell behavior by using fork */
#include "fork.h"

int main(int argc , char ** argv )
{
    if ( argc < 2 ) { 
        printf ("Error : use <executable> <command to execute> \n");
        exit (EXIT_FAILURE) ;
    }
    int pid ;                         /*take the parent id  */ 
        pid = vfork () ; 
        switch ( pid )  { 
        case -1:                      /*vfork failure condition */  
            perror  ("vfork");
            exit (0) ;
            break  ; 
        case  0 :
        execlp (argv[1] , argv[1], argv[2] , NULL ) ; 
        printf("after exec...\n");
        /*launch new exec process*/
        exit(0) ;
       default :
       sleep(1);
       printf ("perent waiting ...\n"); 
   } 

    return 0 ;

}




    

