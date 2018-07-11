#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{

int **p ,r=3,c=3,i,j;
p = new int *[r];

for (i = 0 ; i<r; i++)
{
p[i] = new int [c];
}

for(i=0;i<r;i++)
for(j=0;j<c;j++)
p[i][j] = 0;


for(i=0;i<r;i++)
for(j=0;j<c;j++)
cout << p[i][j]  <<endl;
free(p);
//delete []p;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
cout << p[i][j]  <<endl;
return 0;
}
