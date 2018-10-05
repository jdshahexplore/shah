#include<iostream>
using namespace std;

inline double multiply(double a, double b)
{
    return (a*b);
}

inline double divide(double a, double b)
{
    return (a/b);
}

int main()
{
    double a,b;
    cout<<"Enter First Number = ";
    cin>>a;
    cout<<"Enter Second Number = ";
    cin>>b;
    cout<<"Multiplication of "<<a<<" and "<<b<<" = "<<multiply(a,b)<<endl;
    cout<<"division of "<<a<<" and "<<b<<" = "<<divide(a,b)<<endl;
    return 0;
}
