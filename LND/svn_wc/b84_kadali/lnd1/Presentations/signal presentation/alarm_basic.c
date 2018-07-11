#include"header.h"
#include <signal.h>
#include <unistd.h>

void display_message(int s) {
    printf("alarm activated\n" );
    static int i=0;
    if(i<5)
    {
        i++;
        alarm(2); 
    }   //for every second
    //    signal(SIGALRM, display_message);
}

int main(void) {
    signal(SIGALRM, display_message);
    signal(14, display_message);

    alarm(1);

    while (1) {
    }
    return 0;
}

