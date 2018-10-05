#include<iostream>
using namespace std;

class Vehicle
{
    public:
    float price;
    string year;
    void getdata()
    {
        cout<<"Enter price = ";
        cin>>price;
        cout<<"Enter year = ";
        cin>>year;
    }
    void putdata()
    {
        cout<<"Price = "<<price<<endl;
        cout<<"Year = "<<year<<endl;
    }
};

class Bus:public Vehicle
{
    int seat_cap;
    public:
    void getdata()
    {
        cout<<"Enter Seating Capacity of Bus = ";
        cin>>seat_cap;
        Vehicle::getdata();
    }
    void putdata()
    {
        cout<<"Seating Capacity = "<<seat_cap<<endl;
        Vehicle::putdata();
    }
};

class Truck:public Vehicle
{
    int load_cap;
    public:
    void getdata()
    {
        cout<<"Enter Loading Capacity of Truck = ";
        cin>>load_cap;
        Vehicle::getdata();
    }
    void putdata()
    {
        cout<<"Loading Capacity = "<<load_cap<<endl;
        Vehicle::putdata();
    }
};

int main()
{
    Bus b;
    Truck t;
    int c;
    cout<<"------------Menu-------------"<<endl;
    cout<<" 1: Bus"<<endl;
    cout<<" 2: Truck"<<endl;
    cout<<" 3: Exit"<<endl;
    cout<<"-----------------------------"<<endl;
    read:
    cout<<endl<<"Enter choice = ";
    cin>>c;
    switch(c)
    {
        case 1:
            b.getdata();
            b.putdata();
            goto read;
        case 2:
            t.getdata();
            t.putdata();
            goto read;
        case 3:
            break;
        default:
            cout<<"Wrong choice"<<endl;
            goto read;
    }
    return 0;
}
