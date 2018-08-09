#include <iostream>
using namespace std;
class A
{
const        int x,y;
        static int z;
        A():x(10),y(20)
        {
                cout << "private constructor" << endl;
        }
        public:
        static void fun(void)
        {
                cout << "static mem fun"  << endl;
                A obj;
                obj.display();
                cout << "z:" << z << endl;
        } 
        void display()
        {
                cout << "x:" << x << "  " << "y:" << y << endl; 
        }
};
int A::z =100;
int main(void)
{
        A :: fun();
        return 0;
}
