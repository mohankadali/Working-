#include <linux/fb.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>




int main()
{
struct fb_fix_screeninfo var;
    printf("  %d\n",var.type); 

    return 0;
}
