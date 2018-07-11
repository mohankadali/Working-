#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void wordcount()
{
    char word [10] ;
    int c =0;
    ifstream fin;
    fin.open("text.txt");
    while(!fin.eof())
    {
        fin >> word;
        if(strcmp(word , "He") == 0 || strcmp(word , "She") == 0)
            c++;
    }
    cout << "word count:"<< c<< endl;
    fin.close();
}


int main()
{

    wordcount();
    return 0;

}

