#include <iostream>
using namespace std;
class Sample
{
    private:
        int x;
        double y;
    public :
        Sample(); //Constructor 1
        Sample(int); //Constructor 2
        Sample(int, int); //Constructor 3
        Sample(int, double); //Constructor 4
        void display();
};
void Sample::display()
{
cout << "x:" << x <<  " " << "y:" << y << endl;
}
Sample::Sample()
{
    x =0;
    y =0; 
}
Sample::Sample(int X)
{
    x =X;
    y =0.00; 
}
Sample::Sample(int X,int Y)
{
    x =X;
    y =Y; 
}
Sample::Sample(int X, double Y)
{
    x =X;
    y =Y; 
}
int main()
{

    Sample obj1;
    Sample obj2(10);
    Sample obj3(10,20);
    Sample obj4(10,32.56);
    obj1.display();
    obj2.display();
    obj3.display();
    obj4.display();
    return 0;
}
