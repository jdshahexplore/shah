#include<iostream>
using namespace std;

class Rectangle
{
    int length,breadth;

    public:
    void getdata();
    int area();
};

void Rectangle::getdata()
{
    cout<<"Enter length = ";
    cin>>length;
    cout<<"Enter Breadth = ";
    cin>>breadth;
}

int Rectangle::area()
{
    return (length*breadth);
}

int main()
{
    Rectangle r;
    r.getdata();
    cout<<"Area of rectangle = "<<r.area()<<" sq.unit";
    return 0;
}
