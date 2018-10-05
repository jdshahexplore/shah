#include<iostream>
#include<string.h>
using namespace std;

class Person
{
    public:
    string name;
    string code;
    void getdata()
    {
        cout<<"Enter name of Employee = ";
        cin>>name;
        cout<<"Enter code of Employee = ";
        cin>>code;
    }
    void putdata()
    {
        cout<<"Name of Employee = "<<name<<endl;
        cout<<"Code of Employee = "<<code<<endl;
    }
};

class Account:public Person
{
    public:
    string pay;
    void getdata()
    {
        Person::getdata();
        cout<<"Enter Pay of employee = ";
        cin>>pay;
    }
    void putdata()
    {
        Person::putdata();
        cout<<"Pay of Employee = "<<pay<<endl;
    }
};

class Admin:public Person
{
    public:
    string Exp;
    void getdata()
    {
        cout<<"Enter your experiece = ";
        cin>>Exp;
    }
    void putdata()
    {
        cout<<"Experience = "<<Exp<<endl;
    }
};

class Employee:public Account,public Admin
{
    public:
    void getdata()
    {
        cout<<"----------Enter informtion of Employee-------------"<<endl;
        Account::getdata();
        Admin::getdata();
    }
    void putdata()
    {
        cout<<"---------Employee Information---------"<<endl;
        Account::putdata();
        Admin::putdata();
    }
};

int main()
{
    Employee e;
    e.getdata();
    e.putdata();
    return 0;
}
