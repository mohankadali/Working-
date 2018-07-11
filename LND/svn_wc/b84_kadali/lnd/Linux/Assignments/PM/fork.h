
/* programm to understand the fork behavior on local data */
#ifndef _FORK_H
#define _FORK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

int global_var_experiment(void) ;      /*experiment fork on global var */ 
int local_var_experiment(void) ;      /*experiment fork on local var */ 
int open_my_file_txt (void) ;          /*file operations by  fork & vfork*/
#endif 
