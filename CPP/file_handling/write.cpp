#include<iostream>
#include<fstream>
using namespace std;

int main() 
{
    fstream ofile; 
    ofile.open ("text.txt"); 
    ofile << "geeksforgeeks" << endl;
    cout << "Data written to file" << endl;
    ofile.close(); 
    return 0;
}
