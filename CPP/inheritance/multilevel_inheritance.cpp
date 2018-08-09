#include <iostream>
using namespace std;
class Vehicle 
{
        public:
                Vehicle()
                {
                        cout << "Vehicle constructor" << endl;
                }
                ~Vehicle()
                {
                        cout << "Vehicle destructor" << endl;
                }
};
class fourWheeler: public Vehicle
{
        public:
                fourWheeler()
                {
                        cout<<"fourwheeler constructor"<<endl;
                }
                ~fourWheeler()
                {
                        cout<<"fourwheeler destructor"<<endl;
                }
};
class Car: public fourWheeler
{
        public:
                Car()
                {
                        cout<<"Car constructor"<<endl;
                }
                ~Car()
                {
                        cout<<"Car destructor"<<endl;
                }
};
int main()
{   
        Car obj;
        return 0;
}
