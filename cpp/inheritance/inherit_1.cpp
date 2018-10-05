#include<iostream>
#define PI 3.14
using namespace std;

class Circle
{
    float area;
    public:
    float r;
    void getdata()
    {
        cout<<"Enter radius = ";
        cin>>r;
    }
    void calarea()
    {
        area=PI*r*r;
        cout<<"Area of circle = "<<area<<endl;
    }
};

class Cylinder:public Circle
{
    float h;
    float volume;
    public:
    void getdata()
    {
        Circle::getdata();
        cout<<"Enter height = ";
        cin>>h;
    }
    void calvol()
    {
        volume=PI*r*r*h;
        cout<<"Volume of Cylinder = "<<volume<<endl;
    }
};

int main()
{
    Circle c1;
    Cylinder c2;
    int c;
    cout<<"------------Menu-------------"<<endl;
    cout<<" 1: Area of Circle"<<endl;
    cout<<" 2: Volume of Cylinder"<<endl;
    cout<<" 3: Exit"<<endl;
    cout<<"-----------------------------"<<endl;
    read:
    cout<<endl<<"Enter choice = ";
    cin>>c;
    switch(c)
    {
        case 1:
            c1.getdata();
            c1.calarea();
            goto read;
        case 2:
            c2.getdata();
            c2.calvol();
            goto read;
        case 3:
            break;
        default:
            cout<<"Wrong choice"<<endl;
            goto read;
    }
    return 0;
}
