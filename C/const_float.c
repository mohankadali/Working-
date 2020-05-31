#include <stdio.h>
int main(){
const float f = 10.34f;
float *fp = &f;

*fp = *fp + 1.4f ;

printf("%f\n",f);
return 0;
}
