#include "mypthread.h" 
/*program for synchronous alarm  */
int main(void)
{
  char msg[MSG_SIZE] ; 
  char line [LINE_BUF] ; 
  int  seconds ; 
  int pid ; 
  printf ("Input Formatt :   <seconds>  <space> <Msg>\n");
  while ( 1 ) {
    printf ("Alarm :> "); 
    if ( NULL == fgets ( line , sizeof (line) , stdin ) )  {
      perror ( "fgets"  ) ; 
      exit ( EXIT_FAILURE ) ; 
    }
    /*if input is less then one char skip that iteration  */
    if  (strlen (line )  <= 1 ) 
      continue ; 
    /*parse the input into second and mesg size from line  */
    if (sscanf (line , "%d %64[^\n]" , &seconds , msg) < 2 ) {
      printf ("Bad command \n");  
    } else {
      pid = fork ( )  ; 
      if ( pid < 0 ) { 
        perror ("fork FAIL \n");
        exit ( EXIT_FAILURE ) ; 
      }
      if ( 0 == pid ) {  
        handle_alarm ( seconds , msg ) ; 
      } else {
        handle_zombies( ) ; 
      } 
    }
  } 
  return 0; 
}
