#include <fstream>
#include <iostream>
using namespace std;

int main () {
    char data[100];

    // open a file in write mode.
    ofstream fout;
    fout.open("file.ext");


    cout << "Write the file" << endl;
    cin.getline(data, 100);

    // write inputted data into the file.
    fout << data << endl;

    // close the opened file.
    fout.close();

    // open a file in read mode.
    ifstream fin; 
    fin.open("file.ext"); 
    cout << "Reading from the file" << endl; 
    fin >> data; 

    int i ;
    for (i =0; data[i]!= EOF ; i++)
    {
        if ( data[i] >= 'a' && data[i] <= 'z' )
            data[i] = data[i] - 32; 
    }


    // write the data at the screen.
    cout << data << endl;

    // close the opened file.
    fin.close();

    return 0;
}
