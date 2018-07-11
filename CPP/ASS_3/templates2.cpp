#include <iostream>

using namespace std;
template <class type> void small (type &A,type &temp)
{
    cout << "entered into template fun "<< endl;
    int i;
    temp = A[0];
    for (i = 0;i < B;i++)
    {
        if (A[i] < temp) 
        {
            temp = A[i];
        }  
    }
    cout << "smallest value is : " << temp << endl; 
}
int main()
{
    int i[5] = {1,2,3,7,6};
    double d[5] = {9.64,3.098,7.6,6.245,786};
    float f[5] = {10.2,2.97,3.46,7.78,0.098};

    cout << "for int :" << endl;
    small( i, 5);
    cout <<"for double :" << endl;
    small(d,5);
    cout <<"for float :" << endl;
    small(f,5);

    return 0;
}
