#include<iostream>
using namespace std;

class Rational
{
    int num,den;
    public:
    void getdata()
    {
        cout<<"Enter numerator and denominator = ";
        cin>>num>>den;
    }
    void display()
    {
        cout<<"numerator = "<<num<<"\ndenominator = "<<den<<endl;
    }
    Rational operator +(Rational &);
    Rational operator -(Rational &);
    Rational operator *(Rational &);
    Rational operator /(Rational &);
};

Rational Rational::operator +(Rational & y)
{
    Rational z;
    z.num=num+y.num;
    z.den=den+y.den;
    return z;
}

Rational Rational::operator -(Rational & y)
{
    Rational z;
    z.num=num-y.num;
    z.den=den-y.den;
    return z;
}

Rational Rational::operator *(Rational & y)
{
    Rational z;
    z.num=num*y.num;
    z.den=den*y.den;
    return z;
}

Rational Rational::operator /(Rational & y)
{
    Rational z;
    z.num=num/y.num;
    z.den=den/y.den;
    return z;
}

int main()
{
    Rational x;
    Rational y;
    Rational z;
    int c;
    cout<<"Enter choice"<<endl<<"1: Add\n2: Subtract\n3: Multiply\n4: Divide"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
            cout<<"data for 1st object"<<endl;
            x.getdata();
            cout<<"data for 2nd object"<<endl;
            y.getdata();
            z=x+y;
            cout<<"addition"<<endl;
            z.display();
            break;
        case 2:
            cout<<"data for 1st object"<<endl;
            x.getdata();
            cout<<"data for 2nd object"<<endl;
            y.getdata();
            z=x-y;
            cout<<"subtraction"<<endl;
            z.display();
            break;
        case 3:
            cout<<"data for 1st object"<<endl;
            x.getdata();
            cout<<"data for 2nd object"<<endl;
            y.getdata();
            z=x*y;
            cout<<"multiplication"<<endl;
            z.display();
            break;
        case 4:
            cout<<"data for 1st object"<<endl;
            x.getdata();
            cout<<"data for 2nd object"<<endl;
            y.getdata();
            z=x/y;
            cout<<"division"<<endl;
            z.display();
            break;
    }
    return 0;
}
