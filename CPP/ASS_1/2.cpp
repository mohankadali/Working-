#include <iostream>
using namespace std;
class Rectangle
{
    private:
        float length;
        float width;
    public:
        void setlength(float);
        void setwidth(float);
        float perimeter();
        float area();
        void show();
        int samearea(Rectangle);
};
void Rectangle::setlength(float len)
{
    length = len ;
}
void Rectangle::setwidth(float wid)
{
    width = wid ;
}
float Rectangle::perimeter()
{
    return 2 * (length + width);
}
float Rectangle::area()
{
    return 2 * (length * width);
}

int main()
{
    Rectangle obj1,obj2;
    float len,wid;
    cin >> len >>wid;
    obj1.setlength(len);
    obj1.setwidth(wid);
    cout << "area of rect1:" << obj1.area() << endl;
    cout << "perimeter of rect1:" << obj1.perimeter() << endl;
    cin >> len >>wid;
    obj2.setlength(len);
    obj2.setwidth(wid);
    cout << "area of rect1:" << obj2.area() << endl;
    cout << "perimeter of rect1:" << obj2.perimeter() << endl;
    if (obj1.area() == obj2.area())
        cout << "both areas are same" << endl;
    else
        cout << "both areas are not same" << endl;

    return 0;
}
