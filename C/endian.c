#include <stdio.h>
void endian(char* c, int len){
int j;

for(j=0;j<len;j++)
{
printf("%.2x ",c[j]);
}

printf("\n");
}
int main(){

int i = 0x12345678;

endian((char*)&i,sizeof(i));

return 0;
}
