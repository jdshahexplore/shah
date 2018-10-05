#include<iostream>
#include<string.h>
using namespace std;

class Item
{
    protected:
    int i_code,disc;
    string i_name;
    float i_cost;
    public:
    void getdata()
    {
        cout<<"Enter item code = ";
        cin>>i_code;
        cout<<"Enter item name = ";
        cin>>i_name;
        cout<<"Enter cost = ";
        cin>>i_cost;
        cout<<"Enter discount on item = ";
        cin>>disc;
    }
};

class Employee:public Item
{
    int Emp_code;
    string Emp_name;
    float amount;
    public:
    Employee() {amount=0;}
    void getdata()
    {
        cout<<"Enter Employee Code = ";
        cin>>Emp_code;
        cout<<"Enter Employee Name = ";
        cin>>Emp_name;
        Item::getdata();
        amount=amount+i_cost-(i_cost*disc)/100;
    }
    void putdata()
    {
        cout<<"Employee Code = "<<Emp_code<<endl;
        cout<<"Employee Name = "<<Emp_name<<endl;
        cout<<"Item Code = "<<i_code<<endl;
        cout<<"Item Name = "<<i_name<<endl;
        cout<<"Item Cost = "<<i_cost<<endl;
        cout<<"Discount = "<<disc<<"%"<<endl;
        cout<<"Total amount = "<<amount<<endl;
    }
};

class Customer:public Item
{
    string c_name;
    float amount;
    public:
    Customer() {amount=0;}
    void getdata()
    {
        cout<<"Enter Customer Name = ";
        cin>>c_name;
        Item::getdata();
        amount=amount+i_cost-(i_cost*disc)/100;
    }
    void putdata()
    {
        cout<<"Customer Name = "<<c_name<<endl;
        cout<<"Item Code = "<<i_code<<endl;
        cout<<"Item Name = "<<i_name<<endl;
        cout<<"Item Cost = "<<i_cost<<endl;
        cout<<"Discount = "<<disc<<"%"<<endl;
        cout<<"Total amount = "<<amount<<endl;
    }
};

int main()
{
    Employee e;
    Customer c;
    int ch;
    read:
    cout<<" 1: Customer"<<endl;
    cout<<" 2: Employee"<<endl;
    cout<<" 3: break"<<endl;
    cout<<"Enter choice = ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            c.getdata();
            c.putdata();
            goto read;
        case 2:
            e.getdata();
            e.putdata();
            goto read;
        case 3:
            break;
    }
    return 0;
}
