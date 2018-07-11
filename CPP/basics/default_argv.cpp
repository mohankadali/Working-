#include <iostream>
using namespace std ;
int sum (int ,int = 0, int = 0, int = 0, int = 0);
/*int sum (int a=0, int b=0, int c=0, int d=0, int e=0)
  {
  return a+b+c+d+e ;
  }*/
//int sum (int = 0, int = 0, int = 0, int = 0, int = 0);
int main()
{

  cout << sum(1,2,3,4) << endl;
  cout << sum(1,2,3) << endl;
  cout << sum(1,2) << endl;
  cout << sum(1) << endl;
//  cout << sum() << endl;
  return 0;
}


int sum (int a, int b, int c, int d, int e)
{
  return a+b+c+d+e ;
}

