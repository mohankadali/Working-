
/* programm to understand the fork behavior on local data */
#ifndef _MYPTHREAD_H
#define _MYPTHREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <pthread.h>
#define MSG_SIZE 64 
#define LINE_BUF 120 

void* global_var_experiment(void* ) ;      /*experiment thread on global var */ 
void* local_var_experiment(void* ) ;      /*experiment thread on local var */ 
void* thread_id (void * )   ;
void* thread_id1 (void * )  ;
int thread_create_thread ( void ) ; 
int thread_create_process ( void ) ; 
int process_create_thread ( void ) ; 
int process_create_process ( void ) ; 
void* file_write (void* )  ;
int handle_alarm ( int , char *  );
int handle_zombies ( void ) ;
void * handle_thread_alarm ( void * ) ; 
void * m_handle_thread_alarm ( void * ) ; 

#endif 
