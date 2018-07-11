#include <iostream>
using namespace std;

class dispenserType{
    private:
        int option;
        int flag;
        char ch;
        int input_amount;
    public:
        dispenserType();
        void accept_money(int ,int );
        void release_item();
};
void dispenserType :: accept_money(int input_amount, int req_amount)
{

    if (input_amount == req_amount)
    {
        cout << "please collect your item...." << endl;
    }
    else{
        cout << "please send required amount...." << endl;
    }
}
void dispenserType:: release_item()
{

}
dispenserType :: dispenserType()
{
    while(flag)
    {
        flag = 0 ;
        cout << "Welcome To CandyMachine " << endl;
        cout << "1>pop corn     bye one get one" << endl;
        cout << "2>baby corn   bye two get one " << endl;
        cout << "3>Sweet phan  bye one get one " << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "pop corn : 20 Rs/- " << endl;
                cout << "if you want press Y, otherwise N" << endl;
                cin >> ch;
                if (ch == 'Y'){
                    cout << "send suffient amount" << endl;
                    cin >> input_amount;
                    accept_money(input_amount, 20);
                    release_item();
                }
                else{
                    flag = 1;
                }   
                break;
            case 2:
                cout << "baby corn : 30 Rs/- " << endl;
                cout << "if you want press Y, otherwise N" << endl;
                cin >> ch;
                if (ch == 'Y'){
                    cout << "send suffient amount" << endl;
                    cin >> input_amount;
                    accept_money(input_amount,30);
                    release_item();
                }
                else{
                    flag = 1;
                }   
                break;
            case 3:
                cout << "sweet pan : 40 Rs/- " << endl;
                cout << "if you want press Y, otherwise N" << endl;
                cin >> ch;
                if (ch == 'Y'){
                    cout << "send suffient amount" << endl;
                    cin >> input_amount;
                    accept_money(input_amount,40);
                    release_item();
                }
                else{
                    flag = 1;
                }   
                break;
            default:
                cout << "choose proper option.... " << endl;
                flag = 1;
        }
    }
}
int main(void)
{
    dispenserType obj;
    return 0;
}
