#include <iostream>
using namespace std;
class Box {
    private:
        double length;     // Length of a box
        double breadth;    // Breadth of a box
        double height;     // Height of a box
    public:
        static int objectcount;
        // Constructor definition
        Box(double l = 2.0, double b = 2.0, double h = 2.0) {
            cout <<"Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
            // Increase every time object is created
            objectcount++;
        }
        double Volume() {
            return length * breadth * height;
        }
        static int getcount() {
            return objectcount;
        }
};

int Box::objectcount = 0;

int main(void) {
    cout << "Inital Stage Count: " << Box::getcount() << endl;
    
    Box Box1(3.3, 1.2, 1.5);    // Declare box1
    cout << "volume: " << Box1.Volume() << endl;
    Box Box2(8.5, 6.0, 2.0);    // Declare box2
    cout << "volume: " << Box2.Volume() << endl;
    
    cout << "Final Stage Count: " << Box::getcount() << endl;
    return 0;
}
