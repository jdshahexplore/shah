#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char c;
    fstream fin,fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    while(fin)
    {
        fin.get(c);
        c=toupper(c);
        fout.put(c);
    }
    cout<<"File modified Successfully";
    return 0;
}
