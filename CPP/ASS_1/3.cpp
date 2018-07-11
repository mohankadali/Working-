// constructor overloading //

#include <iostream>
#include <string.h>
using namespace std;
class Test
{
    char paper[20];
    int marks;
    public:
    Test ()    // Function 1
    {
        strcpy (paper, "Computer");
        marks = 0;
    }

    Test (char *p)    // Function 2
    {
        strcpy(paper, p);
        marks = 0;
    }

    Test (int m)    // Function 3
    {
        strcpy(paper,"Computer");
        marks = m;
    }

    Test (char *p, int m)    // Function 4
    {
        strcpy (paper, p);
        marks = m;
    }
    void display();

};
void Test :: display()
{
    cout << "paper:" << paper << endl;
    cout << "marks:" << marks << endl;
}
int main()
{
    Test obj;
    obj.display();
    Test obj1("MATHS");
    obj1.display();
    Test obj2(10);
    obj2.display();
    Test obj3("english",10);
    obj3.display();
}

