#include<iostream>
using namespace std;
class A {
    private:
        int x, y;
    public:
        A(int x1, int y1){
            x = x1;
            y = y1;
        }
        A(const A &p2){
            x = p2.x;
            y = p2.y;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
};
int main()
{
    A p1(10, 15); 
//    Point p2 = p1; // Copy constructor is called here
    A p2 (p1); // Copy constructor is called here
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY() << endl;
    return 0;
}
