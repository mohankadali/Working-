
/*main program to invoke the property of the fork  */

#include "fork.h"

int main(void)
{
    /*invoking the fork properties for experiment */
//    local_var_experiment () ; 
    global_var_experiment () ;
    printf ("Calling for file operation by fork \n");
    open_my_file_txt () ; 

    return 0; 
} 



