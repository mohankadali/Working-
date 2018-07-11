#include <stdio.h>
#include <unistd.h>
int main()
{	
	int i;
	for(i = 0;i < 5;i++) {
//	fprintf(stdout,"hello-out");
	printf("hello-out");

	sleep(1);
	fprintf(stderr,"hello-err");
      }
        return 0;
}
