#include <iostream>
using namespace std;
void swap (int &p , int &q)
{

    int temp;
    temp = p;
    p = q;
    q = temp;

}
int main(void)
{
int x =10,y =20;

swap(x,y);

cout <<"x :"<< x << endl;
cout <<"y :"<< y << endl;
return 0;
}
