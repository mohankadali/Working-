#include <iostream>

using namespace std;
void swap(int &n1,int  &n2)
{
    int temp;
    temp = n1 ;
    n1 = n2;
    n2 = temp;
}
int main()
{
    int num1 , num2;

    cout << "enter the number to be swaped ...." << endl;
    cin >> num1;
    cin >> num2;

    cout << "Before swap:" << endl;
    cout << "num1:" << num1 << "  " << "numn2:" << num2 << endl;
    swap(num1,num2);
    cout << "After swap:" << endl;
    cout << "num1:" << num1 << "  " << "numn2:" << num2 << endl;

    return 0;
}
