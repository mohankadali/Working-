#include <iostream>
using namespace std;
class A
{
        int x,y;
        public:
        A()
        {
                cout << "constructor" <<endl;
                x = 10, y = 20;
        }
        void display()
        {
                cout << "x:" << x << endl << "y:" << y << endl; 
        }
};

int main(void)
{
        A obj;
        obj.display();
        return 0;
}
