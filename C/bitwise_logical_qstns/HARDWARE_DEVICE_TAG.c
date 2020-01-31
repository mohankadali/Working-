#include <stdio.h>
#define MAKE_TAG_CONSTANT(A,B,C,D) (((A) << 24) | ((B) << 16) | ((C) << 8) | (D))
#define HARDWARE_DEVICE_TAG MAKE_TAG_CONSTANT('H', 'W', 'D', 'T')
int main()
{

printf("%d\n",HARDWARE_DEVICE_TAG);
printf("%x\n",HARDWARE_DEVICE_TAG);
printf("%o\n",HARDWARE_DEVICE_TAG);

return 0;
}
