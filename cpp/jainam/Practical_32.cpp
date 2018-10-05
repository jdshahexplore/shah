#include<iostream>
using namespace std;
void readdata(double &a,double &b)
{
    cout<<"\nEnter Two Number : ";
    cin>>a>>b;

    if(!isdigit(a))
        {
            cout<<"Wrong Data Type is keyed";
            cin>>a;
            throw(a);
        }
    else if(!isdigit(b))
        {
            cout<<"Wrong Data Type is keyed";
            cin>>b;
            throw(b);
        }
    try
    {
        throw(a);
    }
    catch(double e)
    {
        cout<<e<<endl;
    }
}
void div(double a,double b)
{
    double d;
    d=a/b;
    cout<<"Divied Two Number Ans : "<<d<<endl;
}
int main()
{
    double a,b;
    readdata(a,b);
    //cout<<a<<endl<<b;
    div(a,b);
}
