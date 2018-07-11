#include <iostream>
using namespace std;
class emp{
    public:
        int  emp_ID;
        char emp_name[20];
        char emp_designation[20];
        void get_employee_info();
};
class salary : public emp{
    private:
        int  basic_pay;
        int HRA;
        int DA;
        int PF;
        int net_pay;
    public:
        void get_salary_info();
        void calculate();
        void display();
};
void salary::display()
{
    cout << "\nEMPLOYEE DETAILS: " << endl;
    cout << "emp ID          \t" << emp_ID << endl;
    cout << "emp name        \t" << emp_name << endl;
    cout << "emp designation \t" << emp_designation << endl;
    cout << "emp basic pay   \t" << basic_pay << endl;
    cout << "emp HRA         \t" << HRA << endl;
    cout << "emp DA          \t" << DA << endl;
    cout << "emp PF          \t" << PF << endl;
    cout << "net pay         \t" << net_pay << endl;
}
void salary::get_salary_info()
{
    cout << "enter emp basic pay...." << endl;
    cin >> basic_pay;
    cout << "enter emp HRA...." << endl;
    cin >> HRA;
    cout << "enter emp DA...." << endl;
    cin >> DA;
    cout << "enter emp PF...." << endl;
    cin >> PF;
}
void salary::calculate()
{
    net_pay = basic_pay + HRA + DA - PF;
}


void emp :: get_employee_info()
{
    cout << "enter emp ID...." << endl;
    cin >> emp_ID;
    cout << "enter emp name...." << endl;
    cin >> emp_name;
    cout << "enter emp designation...." << endl;
    cin >> emp_designation;
}
int main()
{
    int num;
    cout << "enter no of employees:" << endl;
    cin >> num; 
    salary obj[num];
    while (num--){
        obj[num].get_employee_info();
        obj[num].get_salary_info();
        obj[num].calculate();
        obj[num].display();
    }

    return 0;
}

