#include <iostream>
using namespace std;
class EmptyClass{

};

//Empty class that contains only function
class EmptyClassWithFunctions{

        public:
                virtual  void display(){
                }
};
int main(){

        cout << sizeof(EmptyClass)<<endl;
        cout << sizeof(EmptyClassWithFunctions)<<endl;

        return 0;
}

