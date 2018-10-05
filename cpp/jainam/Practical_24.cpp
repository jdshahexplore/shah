//To write a program to find out the payroll system using single inheritance.
#include<iostream>
using namespace std;
class employee
{
    protected:
    string name,depart;
    public:
    void getdata()
    {
        cout<<"Enter Employee Name : ";
        cin>>name;
        cout<<"Enter Department of Employee : ";
        cin>>depart;
    }
    void putdata()
    {
        cout<<"Employee Name is : "<<name<<endl;
        cout<<"Department of "<<name<<" : "<<depart<<endl;
    }
};

class payroll:public employee
{
    int salary;
    public:
    void display()
    {
        getdata();
        cout<<"Enter Salary Of "<<name<<" : ";
        cin>>salary;
        putdata();
        cout<<"Salary Of "<<name<<" : "<<salary<<endl;
    }
};

int main()
{
    payroll p;
    p.display();

    return 0;
}
